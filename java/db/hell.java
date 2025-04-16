import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

class hell {
    public static void main(String[] args) {
        try {
            String url = "jdbc:mysql://localhost:3306/kalika";
            String user = "root";
            String password = "";

            Class.forName("com.mysql.jdbc.Driver");
            Connection con = DriverManager.getConnection(url, user, password);
            System.out.println("Connection Successfully Established.");

            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM bca");

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
            con.close();

        } catch (ClassNotFoundException e) {
            System.err.println("❌ MySQL JDBC Driver not found!");
            e.printStackTrace();
        } catch (SQLException e) {
            System.err.println("❌ SQL Error:");
            e.printStackTrace();
        }
    }
}
