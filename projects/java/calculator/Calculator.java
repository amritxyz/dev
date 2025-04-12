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
        // Frame setup
        frame = new JFrame("Java Calculator");
        frame.setBounds(100, 100, 400, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setLayout(new BorderLayout());

        // Display text field
        textField = new JTextField();
        textField.setEditable(false);
        textField.setFont(new Font("Arial", Font.PLAIN, 28));
        frame.getContentPane().add(textField, BorderLayout.NORTH);
        textField.setColumns(10);

        // Buttons panel
        JPanel panel = new JPanel();
        frame.getContentPane().add(panel, BorderLayout.CENTER);
        panel.setLayout(new GridLayout(5, 4, 10, 10));

        // Buttons layout
        String[] buttonLabels = {
            "7", "8", "9", "/",
            "4", "5", "6", "*",
            "1", "2", "3", "-",
            "0", ".", "=", "+",
            "C"
        };

        for (String label : buttonLabels) {
            JButton button = new JButton(label);
            button.setFont(new Font("Arial", Font.PLAIN, 24));
            button.addActionListener(new ButtonClickListener());
            panel.add(button);
        }
    }

    // Handle button clicks
    private class ButtonClickListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String command = e.getActionCommand();

            if (command.matches("[0-9.]")) {
                currentInput += command;
                textField.setText(currentInput);
            } else if (command.matches("[+\\-*/]")) {
                if (!currentInput.isEmpty()) {
                    firstNumber = Double.parseDouble(currentInput);
                    operation = command;
                    currentInput = "";
                }
            } else if (command.equals("=")) {
                try {
                    double secondNumber = Double.parseDouble(currentInput);
                    double result = 0;

                    switch (operation) {
                        case "+": result = firstNumber + secondNumber; break;
                        case "-": result = firstNumber - secondNumber; break;
                        case "*": result = firstNumber * secondNumber; break;
                        case "/":
                            if (secondNumber == 0) {
                                textField.setText("Error: /0");
                                currentInput = "";
                                return;
                            }
                            result = firstNumber / secondNumber;
                            break;
                    }

                    currentInput = String.valueOf(result);
                    textField.setText(currentInput);
                } catch (NumberFormatException ex) {
                    textField.setText("Invalid input");
                }
            } else if (command.equals("C")) {
                currentInput = "";
                firstNumber = 0;
                operation = null;
                textField.setText("");
            }
        }
    }
}
