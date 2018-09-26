<%@ taglib prefix="S" uri="/struts-tags" %>
<%--
  Created by IntelliJ IDEA.
  User: anlan
  Date: 2018/9/13
  Time: 15:13
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>登陆成功</title>
</head>
<body bgcolor="#8fbc8f">
<div style="text-align: center;margin-top: 160px;">
    <h1>admin</h1>
    <h2><S:text name="welcome"/>！${ name } <S:text name="admin"/></h2>
    <S:text name="your_status_is"/> <S:text name="admin"/><br>
    <S:text name="your_age_is"/> ${ age }
</div>
</body>
</html>
