<%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2018/6/15
  Time: 17:33
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>8_5_welcome</title>
</head>
<body>
welcome!
<%
    String username = (String)session.getAttribute("username");
%>
<%=username%>
</body>
</html>
