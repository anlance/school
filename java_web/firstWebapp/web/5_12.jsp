<%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2018/6/1
  Time: 13:02
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>result</title>
</head>
<body>
    <%
        String account = request.getParameter("account");
        String password = request.getParameter("password");
        if(account.equals(password)){
            out.print("登陆成功");
        }
        else{
            out.print("登陆失败");
        }
    %>
</body>
</html>
