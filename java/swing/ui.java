import java.awt.*;
import javax.swing.*;

class hell {
	public static void main(String[] args) {
		//frame
		JFrame frame = new JFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(500, 500);
		frame.setVisible(true);

		//panel
		JPanel panel1 = new JPanel();
		JPanel panel2 = new JPanel();
		JPanel panel3 = new JPanel();
		JPanel panel4 = new JPanel();
		JPanel panel5 = new JPanel();

		//color
		panel1.setBackground(Color.red);
		panel2.setBackground(Color.green);
		panel3.setBackground(Color.blue);
		panel4.setBackground(Color.yellow);
		panel5.setBackground(Color.black);

		//panel dimension
		panel1.setPreferredSize(new Dimension(100, 100));
		panel2.setPreferredSize(new Dimension(100, 100));
		panel3.setPreferredSize(new Dimension(100, 100));
		panel4.setPreferredSize(new Dimension(100, 100));
		panel5.setPreferredSize(new Dimension(100, 100));

		//panel direction
		frame.add(panel1, BorderLayout.EAST);
		frame.add(panel2, BorderLayout.WEST);
		frame.add(panel3, BorderLayout.SOUTH);
		frame.add(panel4, BorderLayout.NORTH);
		frame.add(panel5, BorderLayout.CENTER);
	}
}
