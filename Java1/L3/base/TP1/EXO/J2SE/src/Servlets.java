            // Utiliser le meme mecanisme dans des sevlets pour creer un acces a une personne, verifier les acces aux forms, etc.
            // Example of how to use the same mechanism in servlets
            // This is a simple example of a servlet that checks user login

            // Import necessary packages for servlet

            public class LoginServlet extends HttpServlet {
                protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
                    response.setContentType("text/html");
                    PrintWriter out = response.getWriter();

                    String login = request.getParameter("login");
                    String pwd = request.getParameter("pwd");

                    try {
                        // Load JDBC driver
                        Class.forName("com.mysql.jdbc.Driver");

                        // Establish connection
                        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mysql", "root", "");

                        // Create SQL query to check login credentials
                        String sql = "SELECT * FROM PERS WHERE login=? AND pwd=?";
                        PreparedStatement pstmt = conn.prepareStatement(sql);
                        pstmt.setString(1, login);
                        pstmt.setString(2, pwd);

                        ResultSet rs = pstmt.executeQuery();

                        if (rs.next()) {
                            out.println("Login successful! Welcome " + login);
                        } else {
                            out.println("Invalid login or password");
                        }

                        // Close the connection
                        conn.close();
                    } catch (ClassNotFoundException e) {
                        out.println("Driver not loaded!");
                        e.printStackTrace();
                    } catch (SQLException e) {
                        out.println("Connection problem!");
                        e.printStackTrace();
                    }
                }

                protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
                    doPost(request, response);
                }
            }
            

