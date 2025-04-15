import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class MySQLConnect {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/kalika"; // Replace with your DB name
        String user = "root"; // XAMPP default user
        String password = ""; // XAMPP default has no password, unless you changed it

        try {
            // Load MySQL JDBC Driver (optional for modern Java, but good for compatibility)
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Create connection
            Connection conn = DriverManager.getConnection(url, user, password);
            System.out.println("✅ Connected to the database successfully!");

            // Create a statement
            Statement stmt = conn.createStatement();

            // Execute a query
            ResultSet rs = stmt.executeQuery("SELECT * FROM bca");

            // Move to the first row and print data if available
            if (rs.next()) {
                System.out.println();
                System.out.println("Database (Bca table): ");
                System.out.println("Id: " + rs.getInt(1));
                System.out.println("Name: " + rs.getString(2));
                System.out.println("Semester: " + rs.getInt(1));
            } else {
                System.out.println("No data found in 'bca' table.");
            }

            // Close resources
            rs.close();
            stmt.close();
            conn.close();

        } catch (ClassNotFoundException e) {
            System.err.println("❌ MySQL JDBC Driver not found!");
            e.printStackTrace();
        } catch (SQLException e) {
            System.err.println("❌ SQL Error:");
            e.printStackTrace();
        }
    }
}
