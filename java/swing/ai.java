import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class StyledForm {
	public static void main(String[] args) {
		// Enable anti-aliasing for better text quality
		System.setProperty("swing.aatext", "true");
		UIManager.put("TextField.font", new Font("Hack", Font.PLAIN, 16));
		UIManager.put("TextField.foreground", new Color(50, 50, 50));
		UIManager.put("TextField.background", new Color(255, 255, 255));
		UIManager.put("TextField.border", new LineBorder(Color.GRAY));

		try {
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		} catch (Exception e) {
			e.printStackTrace();
		}

		// Create the frame
		JFrame frame = new JFrame("Styled User Form");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(400, 250);
		frame.setLayout(new BorderLayout());

		// Panel to hold the form
		JPanel panel = new JPanel(new GridLayout(4, 2, 10, 10));
		panel.setBorder(new EmptyBorder(15, 15, 15, 15));
		panel.setBackground(new Color(245, 245, 245));

		// Create form elements with custom styling
		Font labelFont = new Font("Hack", Font.BOLD, 14);
		Font fieldFont = new Font("Hack", Font.PLAIN, 16); // Set font for fields
		Color fieldBg = new Color(255, 255, 255);
		Color fieldFg = new Color(50, 50, 50);
		LineBorder fieldBorder = new LineBorder(Color.GRAY, 1, true);

		// Create text fields
		JTextField nameField = new JTextField();
		nameField.setPreferredSize(new Dimension(150, 25));
		styleField(nameField, fieldFont, fieldBg, fieldFg, fieldBorder);

		JTextField emailField = new JTextField();
		emailField.setPreferredSize(new Dimension(150, 25));
		styleField(emailField, fieldFont, fieldBg, fieldFg, fieldBorder);

		JTextField ageField = new JTextField();
		ageField.setPreferredSize(new Dimension(150, 25));
		styleField(ageField, fieldFont, fieldBg, fieldFg, fieldBorder);

		JButton submitButton = new JButton("Submit");
		submitButton.setFont(new Font("Hack", Font.BOLD, 14));
		submitButton.setBackground(new Color(50, 150, 250));
		submitButton.setForeground(Color.WHITE);
		submitButton.setFocusPainted(false);
		submitButton.setBorder(new LineBorder(new Color(30, 100, 200), 1, true));

		// Add elements to the panel
		panel.add(new JLabel("Name:"));
		panel.add(nameField);

		panel.add(new JLabel("Email:"));
		panel.add(emailField);

		panel.add(new JLabel("Age:"));
		panel.add(ageField);

		panel.add(new JLabel()); // empty placeholder
		panel.add(submitButton);

		// Add panel to frame
		frame.add(panel, BorderLayout.CENTER);

		// Add action listener
		submitButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				String message = String.format("Name: %s\nEmail: %s\nAge: %s",
						nameField.getText(), emailField.getText(), ageField.getText());
				JOptionPane.showMessageDialog(frame, message, "Form Submitted",
						JOptionPane.INFORMATION_MESSAGE);
			}
		});

		// Display the frame
		frame.setLocationRelativeTo(null);
		frame.setVisible(true);
	}

	// Method to apply styling to fields
	private static void styleField(JTextField field, Font font, Color bg, Color fg, Border border) {
		field.setFont(font);
		field.setBackground(bg);
		field.setForeground(fg);
		field.setBorder(border);
		field.setMargin(new Insets(2, 5, 2, 5)); // Adjust margin for better fit
	}
}
