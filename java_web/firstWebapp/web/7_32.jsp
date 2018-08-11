<%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2018/6/6
  Time: 12:33
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>jsp内置对象_7_32</title>
    </head>
    <body>
    <%
        String act=null;
        String pwd=null;
        String remb=null;
        act = request.getParameter("account");
        pwd = request.getParameter("password");
        remb = request.getParameter("remember");
        if(act!=null&&!act.equals("")&&pwd!=null&&act.equals(pwd)){
            out.write("登录成功，欢迎");
            if(remb!=null){
                Cookie cookie1 = new Cookie("act",act);
                Cookie cookie2 = new Cookie("pwd",pwd);
                cookie1.setMaxAge(60);
                cookie2.setMaxAge(60);
                response.addCookie(cookie1);
                response.addCookie(cookie2);
            }
            out.write("<br>");
            out.write("<input type='button' name='exit' onclick='exit()' value='退出登录'>");
            out.write("<script type='text/javascript'>");
            out.write("var exit = function(){" +
                    "self.location='7_31.jsp';" +
                    "}" +
                    "</script>");
        }
        else{
            if(act==null||pwd==null){
                out.write("你已经退出，2s后回到登录界面，请重新登录");
                response.setHeader("refresh", "2;url=7_31.jsp");
            }
            else{
                out.write("登陆失败<br>");
                out.write("2s后返回登录界面");
                response.setHeader("refresh", "2;url=7_31.jsp");
            }
        }
    %>
    </body>
</html>
