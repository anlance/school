package club.anlan;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.*;
import java.util.ArrayList;

@WebServlet(name = "Servlet_8_21")
public class Servlet_8_21 extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        MySession(request,response);
        select(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request,response);
    }

    //查询数据库
    protected void select(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
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
                        "<td><a href ='Servlet_8_21?bookName="+bookName+"&id="+id+"'>添加到购物车</a></td>"+
                        "</tr>");
            }
            out.write("</table>");
            out.write("<a href ='Servlet_8_22?bookName="+bookName+"'>查看购物车</a>");
            conn.close();
            stat.close();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (SQLException e) {
            e.printStackTrace();
        }

    }

    //Session处理
    protected void MySession(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
        request.setCharacterEncoding("gb2312");
        response.setContentType("text/html;charset=gb2312");
        HttpSession session = request.getSession();
        ArrayList books = (ArrayList)session.getAttribute("books");
        if(books==null){
            books = new ArrayList();
            session.setAttribute("books",books);
        }
        String bookId = request.getParameter("id");
        if(bookId!=null){
            bookId = new String(bookId.getBytes("iso-8859-1"),"utf-8");
            books.add(bookId);
        }
    }

}
