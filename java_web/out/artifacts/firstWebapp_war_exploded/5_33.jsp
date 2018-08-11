<%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2018/6/1
  Time: 15:14
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>display</title>
</head>
    <body>
    <%
        String account = request.getParameter("account1");
        String name = request.getParameter("name");
        String[] phoneNumber = request.getParameterValues("phoneNumber");
        out.println("账户:  "+account+"<br>");
        out.println("name:  "+name+"<br>");
        for(int i=0;i<phoneNumber.length;i++){
            out.println("电话号码"+(i+1)+":  "+phoneNumber[i]+"<br>");
        }
    %>
    </body>
</html>
