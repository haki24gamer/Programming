import java.sql.*;

public class J2SE {
    public static void main(String[] args) {
        Connection conn = null;
        try {
            // Chargement du driver JDBC
            Class.forName("com.mysql.jdbc.Driver");
            System.out.println("Driver charge correctement!");

            // Connexion a la base de donnees
            conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mysql", "root", "");
            System.out.println("Connexion etablie avec succes");

            // Creer une table PERS(id, login, pwd)
            Statement stmt = conn.createStatement();
            String sql = "CREATE TABLE PERS (id INT PRIMARY KEY, login VARCHAR(50), pwd VARCHAR(50))";
            stmt.executeUpdate(sql);
            System.out.println("Table PERS creee avec succes");

            // Inserer des donnees dans la table PERS
            sql = "INSERT INTO PERS VALUES (1, 'Ahmed', '123')";
            stmt.executeUpdate(sql);
            sql = "INSERT INTO PERS VALUES (2, 'Omar', '456')";
            stmt.executeUpdate(sql);
            sql = "INSERT INTO PERS VALUES (3, 'Ali', '789')";
            stmt.executeUpdate(sql);

            // Afficher toutes les personnes presentes
            sql = "SELECT * FROM PERS";
            ResultSet rs = stmt.executeQuery(sql);
            while (rs.next()) {
                System.out.println("ID: " + rs.getInt("id") + ", Login: " + rs.getString("login") + ", Password: " + rs.getString("pwd"));
            }


            // Utiliser le meme mecanisme dans des sevlets pour creer un acces a une personne, verifier les acces aux forms, etc.

            



            // Fermer la connexion
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