import java.sql.*;

public class Jdbctest {
    public static void main(String[] args) {
        Connection conn = null;
        try {
            // Chargement du driver JDBC
            Class.forName("com.mysql.jdbc.Driver");
            System.out.println("Driver O.K.");

            // Connexion a la base de donnees
            String url = "jdbc:mysql://localhost:3306/test";
            String user = "root";
            String passwd = "root";

            conn = DriverManager.getConnection(url, user, passwd);
            System.out.println("Connexion etablie avec succes");

            conn.close();
            
        } catch (ClassNotFoundException e) {
            System.err.println("Driver non charge!");
            e.getMessage();
            e.getStackTrace();
        } catch (SQLException e) {
            System.err.println("Erreur de connexion a la base de donnees");
            e.getMessage();
            e.getStackTrace();
        }
    }
}