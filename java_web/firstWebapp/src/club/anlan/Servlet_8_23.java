package club.anlan;

//后来合在了Servlet_8_21

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
import java.util.ArrayList;

@WebServlet(name = "Servlet_8_23")
public class Servlet_8_23 extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
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

        //跳转
        ServletContext application = this.getServletContext();
        RequestDispatcher rd = application.getRequestDispatcher("/club/anlan/Servlet_8_21");
        rd.forward(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request,response);
    }
}
