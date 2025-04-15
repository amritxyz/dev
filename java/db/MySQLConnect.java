import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class MySQLConnect {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/kalika"; // Replace with your DB name
        String user = "root"; // XAMPP default user
        String password = ""; // XAMPP default has no password, unless you changed it

        try {
            // Load MySQL JDBC Driver (required for some Java versions)
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Create connection
            Connection conn = DriverManager.getConnection(url, user, password);
            System.out.println("✅ Connected to the database successfully!");

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
