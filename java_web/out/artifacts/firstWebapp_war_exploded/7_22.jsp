<%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2018/6/5
  Time: 8:54
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>jsp内置对象_7_22</title>
    </head>
    <body>
        <%
            String act = request.getParameter("account");
            String pwd = request.getParameter("password");
            String remb = request.getParameter("remember");
            if(act!=null&&pwd!=null&&act.equals(pwd)){
                out.write("登录成功，欢迎");
                if(remb!=null){
                    Cookie cookie1 = new Cookie("act",act);
                    Cookie cookie2 = new Cookie("pwd",pwd);
                    cookie1.setMaxAge(60);
                    cookie2.setMaxAge(60);
                    response.addCookie(cookie1);
                    response.addCookie(cookie2);
                }
            }
            else{
                out.write("登陆失败<br>");
                out.write("2s后返回登录界面");
                response.setHeader("refresh", "2;url=7_21.jsp");
            }
        %>
    </body>
</html>
