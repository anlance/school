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
import java.util.ArrayList;

@WebServlet(name = "Servlet_8_5")
public class Servlet_8_5 extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        String username = request.getParameter("username");
        String password = request.getParameter("password");
        HttpSession session = request.getSession();
        String targetUrl="";
        if(username.equals(password)){
            targetUrl = new String("/8_5_welcome.jsp");
            session.setAttribute("username",username);
        }
        else{
            targetUrl = new String("/8_5_login.jsp");
        }
        String contextPath =request.getContextPath();
        response.sendRedirect(contextPath+targetUrl);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request,response);
    }

}
