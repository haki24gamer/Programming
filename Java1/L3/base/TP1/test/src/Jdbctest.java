import java.sql.*;

public class Jdbctest {
    public static void main(String[] args) {
        Connection conn = null;
        try {
            // Chargement du driver JDBC
            Class.forName("com.mysql.jdbc.Driver");
            System.out.println("Driver charge correctement!");

            // Connexion a la base de donnees
            conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mysql", "root", "");
            System.out.println("Connexion etablie avec succes");

            Statement statement = conn.createStatement();
            ResultSet resultSet = statement.executeQuery("SHOW TABLES");

            while (resultSet.next()) {
                System.out.println(resultSet.getString(1));
            }


            conn.close();
            
        } catch (ClassNotFoundException e) {
            System.err.println("Driver non charge!");
            e.getMessage();
            e.getStackTrace();
        } catch (SQLException e) {
            System.err.println("Probleme de connexion!");
            e.getMessage();
            e.getStackTrace();
        }
    }
}