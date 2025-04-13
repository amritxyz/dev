import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.IOException;
import javax.swing.filechooser.FileNameExtensionFilter;

public class MinimalMusicPlayer extends JFrame {
    private JButton selectButton;
    private JButton playPauseButton;
    private File selectedFile;
    private Process ffplayProcess;
    private boolean isPlaying = false;

    public MinimalMusicPlayer() {
        setTitle("Minimal Music Player");
        setSize(300, 100);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        getContentPane().setBackground(Color.BLACK);
        setLayout(new FlowLayout());

        selectButton = new JButton("🎵 Select Music");
        playPauseButton = new JButton("▶️ Play");
        selectButton.setForeground(Color.WHITE);
        playPauseButton.setForeground(Color.WHITE);
        selectButton.setBackground(Color.DARK_GRAY);
        playPauseButton.setBackground(Color.DARK_GRAY);

        add(selectButton);
        add(playPauseButton);

        selectButton.addActionListener(e -> selectMusic());
        playPauseButton.addActionListener(e -> togglePlayPause());

        setVisible(true);
    }

    private void selectMusic() {
        JFileChooser chooser = new JFileChooser();
        chooser.setDialogTitle("Select a music file");
        chooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
        chooser.setAcceptAllFileFilterUsed(true);

        FileNameExtensionFilter filter = new FileNameExtensionFilter(
                "Audio Files", "mp3", "wav", "flac", "ogg"
                );
        chooser.setFileFilter(filter);

        int result = chooser.showOpenDialog(this);
        if (result == JFileChooser.APPROVE_OPTION) {
            selectedFile = chooser.getSelectedFile();
            stopPlayback();
            playMusic();
        }
    }

    private void togglePlayPause() {
        if (selectedFile == null) return;

        if (isPlaying) {
            stopPlayback();
            playPauseButton.setText("▶️ Play");
        } else {
            playMusic();
            playPauseButton.setText("⏸ Pause");
        }
    }

    private void playMusic() {
        if (selectedFile == null) return;

        try {
            ffplayProcess = new ProcessBuilder("ffplay", "-nodisp", "-autoexit", selectedFile.getAbsolutePath())
                .redirectErrorStream(true)
                .start();
            isPlaying = true;
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    private void stopPlayback() {
        if (ffplayProcess != null && ffplayProcess.isAlive()) {
            ffplayProcess.destroy();
        }
        isPlaying = false;
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(MinimalMusicPlayer::new);
    }
}
