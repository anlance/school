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

@WebServlet(name = "Servlet_8_22")
public class Servlet_8_22 extends javax.servlet.http.HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        MySession(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request,response);
    }

    //查询数据库
    protected void select(HttpServletRequest request, HttpServletResponse response, ArrayList bookId) throws ServletException, IOException {
        request.setCharacterEncoding("gb2312");
        response.setContentType("text/html;charset=gb2312");
        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/web7","root","255211");
            Statement stat = conn.createStatement();
            String sql = "";
            String booksId="";
            PrintWriter out = response.getWriter();
            out.write("<table>");
            out.write("<tr>" +
                    "<th>书单号</th>" +
                    "<th>书名</th>" +
                    "<th>价格</th>" +
                    "</tr>");
            ResultSet rs=null;
            for(int i=0;i<bookId.size();i++){
                if(i==bookId.size()-1){
                    booksId += "ID = '"+bookId.get(i).toString()+"' ";
                }
                else{
                    booksId += ("ID = '"+bookId.get(i).toString()+"' OR ");
                }
            }
            sql+="select * from T_BOOK where "+booksId+";";
            rs = stat.executeQuery(sql);
            while(rs.next()){
                String id = rs.getString("ID");
                String name = rs.getString("name");
                String price = rs.getString("price");
                out.write("<tr>" +
                        "<td>" +id+"</td>"+
                        "<td>" +name+"</td>"+
                        "<td>" +price+"</td>" +
                        "<td><a href ='Servlet_8_22?id="+id+"'>从购物车中删除</a></td>"+
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

    //Session处理
    protected void MySession(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
        request.setCharacterEncoding("gb2312");
        response.setContentType("text/html;charset=gb2312");
        HttpSession session = request.getSession();
        ArrayList books = (ArrayList)session.getAttribute("books");
        PrintWriter out = response.getWriter();
        if(books==null){
            books = new ArrayList();
            session.setAttribute("books",books);
        }
        String bookId=request.getParameter("id");
        String bookName=request.getParameter("bookName");
        if(books.size()!=0){
            if(bookId!=null){
                bookId = new String(bookId.getBytes("iso-8859-1"),"utf-8");
                for(int i=0;i<books.size();i++){
                    String tempBook=(String)books.get(i);
                    if(bookId.equals(tempBook)){
                        books.remove(i);
                        break;
                    }
                }
            }
            if(books.size()!=0){
                out.write("购物车中的内容：<br>");
                select(request,response,books);
            }
            else{
                out.write("购物车是空的<br>");
            }
        }
        else{
            out.write("购物车是空的<br>");
        }
        out.write("<a href ='/8_2.jsp'>查询书籍</a>");
    }
}
