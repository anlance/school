<%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2018/6/1
  Time: 12:57
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>login</title>
</head>
<body>
    这是一个登录表单，如果输入的账号密码相等，将显示登陆成功，否则显示登录失败<br>
    <form action="5_12.jsp" method="post">
        请输入账号：<input name="account" type="text"><br>
        请输入密码：<input name="password" type="password"><br>
        <input type="submit" value="登录">
    </form>
</body>
</html>
