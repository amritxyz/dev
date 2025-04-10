import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class hell {
    public static void main(String[] args) {

        JFrame frame = new JFrame("My Frame");

        //frame.setSize(500, 400); // x-dimension & y-dimension
        //frame.setLocation(100,50); // width & height
        frame.setBounds(500,100,400,300);
        frame.setTitle("Wayland client");
        ImageIcon icon = new ImageIcon("~/.local/ss/1_screenshot.png"); //Same directory
        frame.setIconImage(icon.getImage());  //method of image icon for loading image in frame

        Container c= frame.getContentPane();  //change the background of jframe contentpane using awt class container
        c.setBackground(Color.green);
        frame.setResizable(false);  //disable
        frame.setLayout(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JLabel label = new JLabel("Click the button!");
        label.setBounds(50, 50, 200, 30);
        Font font =new Font("Hack",Font.BOLD,15);
        label.setFont(font);
        frame.add(label);

        JButton button = new JButton("Click Me");
        button.setBounds(50, 100, 120, 30);

        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                label.setText("Button Clicked!");
            }
        });


        frame.add(button);

        frame.setVisible(true);
    }
}
