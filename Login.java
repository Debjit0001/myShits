package com.smartprogramming.login;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class Login extends HttpServlet {
    private static final long serialVersionUID = 1L;

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        String email = request.getParameter("email");
        String password = request.getParameter("password");

        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/your_database_name", "root", "root"); 
            PreparedStatement ps = con.prepareStatement("select * from register where email=? and password=?");
            ps.setString(1, email);
            ps.setString(2, password);
            ResultSet rs = ps.executeQuery();

            if (rs.next()) {
                HttpSession session = request.getSession();
                session.setAttribute("username", rs.getString("name")); 
                response.sendRedirect("profile.jsp");
            } else {
                out.println("<html><body>");
                out.println("<h3><font color='red'>Email or Password is invalid</font></h3>");
                out.println("<a href='login.jsp'>Try Again</a>");
                out.println("</body></html>");
            }

            con.close();
        } catch (Exception e) {
            out.println(e);
        }
    }
}
