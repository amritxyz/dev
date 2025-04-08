import javax.swing.*;
import java.awt.*;

public class ButtonExample {
	public static void main(String[] args) {
		try {
			// Set system look and feel for better compatibility
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		} catch (Exception ignored) {}

		JFrame frame = new JFrame("Black Background Button");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(300, 200);
		frame.setLocationRelativeTo(null);

		JPanel panel = new JPanel();
		panel.setBackground(Color.BLACK);
		panel.setLayout(new FlowLayout());

		JButton button = new JButton("Click me!");
		button.setForeground(Color.WHITE);
		button.setBackground(Color.DARK_GRAY);
		button.setFocusPainted(false);

		button.addActionListener(e -> {
			JOptionPane.showMessageDialog(frame, "Clicked!");
		});

		panel.add(button);
		frame.setContentPane(panel);

		// Repaint to force render
		frame.revalidate();
		frame.repaint();
		frame.setVisible(true);
	}
}
