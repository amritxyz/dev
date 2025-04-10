import java.awt.*;
import java.awt.font.LayoutPath;
import javax.swing.*;

class ui {
	public static void main(String[] args) {
		// JFrame
		JFrame frame = new JFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(500, 500);
		frame.setLayout(new BorderLayout(10, 10));
		frame.setVisible(true);

		// panels
		JPanel panel1 = new JPanel();
		JPanel panel2 = new JPanel();
		JPanel panel3 = new JPanel();
		JPanel panel4 = new JPanel();
		JPanel panel5 = new JPanel();

		// colors on pannel
		panel1.setBackground(Color.red);
		panel2.setBackground(Color.green);
		panel3.setBackground(Color.blue);
		panel4.setBackground(Color.yellow);
		panel5.setBackground(Color.black);

		// dimension
		panel1.setPreferredSize(new Dimension(100, 100));
		panel2.setPreferredSize(new Dimension(100, 100));
		panel3.setPreferredSize(new Dimension(100, 100));
		panel4.setPreferredSize(new Dimension(100, 100));
		panel5.setPreferredSize(new Dimension(100, 100));

		// ----------------- Sub Panels -----------------

		// panels
		JPanel panel6 = new JPanel();
		JPanel panel7 = new JPanel();
		JPanel panel8 = new JPanel();
		JPanel panel9 = new JPanel();
		JPanel panel10 = new JPanel();

		// colors on pannel
		panel6.setBackground(Color.MAGENTA);
		panel7.setBackground(Color.PINK);
		panel8.setBackground(Color.LIGHT_GRAY);
		panel9.setBackground(Color.CYAN);
		panel10.setBackground(Color.DARK_GRAY);

		panel5.setLayout(new BorderLayout());

		// dimension
		panel6.setPreferredSize(new Dimension(50, 50));
		panel7.setPreferredSize(new Dimension(50, 50));
		panel8.setPreferredSize(new Dimension(50, 50));
		panel9.setPreferredSize(new Dimension(50, 50));
		panel10.setPreferredSize(new Dimension(50, 50));

		panel5.add(panel6, BorderLayout.EAST);
		panel5.add(panel7, BorderLayout.WEST);
		panel5.add(panel8, BorderLayout.SOUTH);
		panel5.add(panel9, BorderLayout.NORTH);
		panel5.add(panel10, BorderLayout.CENTER);

		// ----------------- Sub Panels -----------------

		// where to add
		frame.add(panel1, BorderLayout.EAST);
		frame.add(panel2, BorderLayout.WEST);
		frame.add(panel3, BorderLayout.SOUTH);
		frame.add(panel4, BorderLayout.NORTH);
		frame.add(panel5, BorderLayout.CENTER);
	}
}
