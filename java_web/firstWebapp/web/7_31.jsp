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
        <title>jsp内置对象_7_31</title>
    </head>
    <body>
    <%
        String act = null;
        String pwd = null;
        String exit = null;
        exit = request.getParameter("exit");
        Cookie[] cookies = request.getCookies();


        if(cookies!=null){
            Cookie cookie1 = null;
            Cookie cookie2 = null;
            for(int i=0;i<cookies.length;i++){
                if(cookies[i].getName().equals("act")){
                    act = cookies[i].getValue();
                    cookie1=cookies[i];
                }
                if(cookies[i].getName().equals("pwd")){
                    pwd = cookies[i].getValue();
                    cookie2=cookies[i];
                }
                if(exit!=null&&act.equals(pwd)){
                    cookie1.setMaxAge(0);
                    cookie2.setMaxAge(0);
                    response.addCookie(cookie1);
                    response.addCookie(cookie2);
                }
            }
            if(exit!=null&&act!=null&&pwd!=null){
                response.sendRedirect("7_32.jsp?account="+act+"&password="+pwd);
            }
            else{
                out.write("<form action='7_32.jsp' method='post'>");
                out.write("用户名：<input type='text' name='account'><br>");
                out.write("密码：<input type='password' name='password'><br>");
                out.write("<input type='checkbox' name='remember'>记住用户名<br>");
                out.write("<input type='submit' value='登录'><br>");
                out.write("</form>");
            }
        }
    %>
    </body>
</html>
