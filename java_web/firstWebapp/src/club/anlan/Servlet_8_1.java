package club.anlan;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.*;

@WebServlet(name = "Servlet_8_1")
public class Servlet_8_1 extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("gb2312");
        response.setContentType("text/html;charset=gb2312");
        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/web7","root","255211");
            Statement stat = conn.createStatement();
            String bookName = request.getParameter("bookName");
            String sql = "select * from T_BOOK where name LIKE '%"+bookName+"%'";
            ResultSet rs = stat.executeQuery(sql);
            PrintWriter out = response.getWriter();
            out.write("<table>");
            out.write("<tr>" +
                    "<th>书单号</th>" +
                    "<th>书名</th>" +
                    "<th>价格</th>" +
                    "</tr>");
            while(rs.next()){
                String id = rs.getString("ID");
                String name = rs.getString("name");
                String price = rs.getString("price");
                out.write("<tr>" +
                        "<td>" +id+"</td>"+
                        "<td>" +name+"</td>"+
                        "<td>" +price+"</td>" +
                        "</tr>");
            }
            out.write("</table>");
            conn.close();
            stat.close();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (SQLException e) {
            e.printStackTrace();
        }

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request,response);
        PrintWriter out = response.getWriter();
        out.write("ssss"+"<br>");
    }

}
