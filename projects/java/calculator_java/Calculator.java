import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Calculator {

    private JFrame frame;
    private JTextField textField;
    private String currentInput = "";
    private double firstNumber;
    private String operation;

    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            try {
                Calculator window = new Calculator();
                window.frame.setVisible(true);
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }

    public Calculator() {
        initialize();
    }

    private void initialize() {
        // Create the frame
        frame = new JFrame();
        frame.setBounds(100, 100, 400, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setLayout(new BorderLayout());

        // Create the text field
        textField = new JTextField();
        textField.setEditable(false);
        textField.setFont(new Font("Arial", Font.PLAIN, 24));
        frame.getContentPane().add(textField, BorderLayout.NORTH);
        textField.setColumns(10);

        // Create panel for buttons
        JPanel panel = new JPanel();
        frame.getContentPane().add(panel, BorderLayout.CENTER);
        panel.setLayout(new GridLayout(4, 4, 10, 10));

        // Create buttons
        String[] buttonLabels = {
            "7", "8", "9", "/",
            "4", "5", "6", "*",
            "1", "2", "3", "-",
            "0", ".", "=", "+"
        };

        for (String label : buttonLabels) {
            JButton button = new JButton(label);
            button.setFont(new Font("Arial", Font.PLAIN, 24));
            button.addActionListener(new ButtonClickListener());
            panel.add(button);
        }
    }

    // ActionListener to handle button clicks
    private class ButtonClickListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String command = e.getActionCommand();

            // Handle numbers and decimal point
            if (command.charAt(0) >= '0' && command.charAt(0) <= '9' || command.equals(".")) {
                currentInput += command;
                textField.setText(currentInput);
            }
            // Handle the four operations
            else if (command.equals("/") || command.equals("*") || command.equals("-") || command.equals("+")) {
                firstNumber = Double.parseDouble(currentInput);
                operation = command;
                currentInput = "";
            }
            // Handle the equals button
            else if (command.equals("=")) {
                double secondNumber = Double.parseDouble(currentInput);
                double result = 0;

                switch (operation) {
                    case "+":
                        result = firstNumber + secondNumber;
                        break;
                    case "-":
                        result = firstNumber - secondNumber;
                        break;
                    case "*":
                        result = firstNumber * secondNumber;
                        break;
                    case "/":
                        if (secondNumber != 0) {
                            result = firstNumber / secondNumber;
                        } else {
                            textField.setText("Error");
                            return;
                        }
                        break;
                }

                currentInput = String.valueOf(result);
                textField.setText(currentInput);
            }
        }
    }
}
