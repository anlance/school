package club.anlan;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

@WebFilter(filterName = "Filter_8_5")
public class Filter_8_5 implements Filter {
    public void destroy() {
    }

    public void doFilter(ServletRequest req, ServletResponse resp, FilterChain chain) throws ServletException, IOException {
        HttpServletRequest request = (HttpServletRequest)req;
        HttpServletResponse response = (HttpServletResponse)resp;
        String currentUrl = request.getRequestURI();
        String contextPath = request.getContextPath();
        String path = currentUrl.substring(contextPath.length());
        if(path.equals("/8_5_welcome.jsp")){
            HttpSession session = request.getSession();
            String username = (String)session.getAttribute("username");
            if(username==null){
                System.out.println("未登录访问欢迎界面，请登录！");
                response.sendRedirect(contextPath+"/8_5_login.jsp");
            }
        }
        chain.doFilter(req, resp);
    }

    public void init(FilterConfig config) throws ServletException {

    }

}
