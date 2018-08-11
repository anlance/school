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
        <title>jsp内置对象_7_21_login</title>
    </head>
    <body>
        <%
            String act = null;
            String pwd = null;
            Cookie[] cookies = request.getCookies();
            if(cookies!=null){
                for(int i=0;i<cookies.length;i++){
                    if(cookies[i].getName().equals("act"))
                        act = cookies[i].getValue();
                    if(cookies[i].getName().equals("pwd"))
                        pwd = cookies[i].getValue();
                }
                if(act!=null&&pwd!=null){
                    response.sendRedirect("7_22.jsp?account="+act+"&password="+pwd);
                }
                else{
                    out.write("<form action='7_22.jsp' method='post'>");
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
