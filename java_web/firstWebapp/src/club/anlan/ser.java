package club.anlan;

import java.io.IOException;
import java.util.Date;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class ser extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		String s = request.getParameter("idea");
		//request.setAttribute("s", s);
		Date d = new Date();
		System.out.println(s);
		HttpSession session = request.getSession();
		session.setAttribute("question", s);
		//request.getRequestDispatcher("/autocontact.jsp").forward(request, response);
		String str = d.toLocaleString() + "hello!";
		response.sendRedirect("/autocontact.jsp?info="+str);
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
