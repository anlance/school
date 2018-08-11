<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<html>
<head>
第四章第二题<br><br>
</head>
<body>
	<%
		String str = request.getParameter("n");
		int number = Integer.parseInt(str);
	 %>
	 该数字的平方为：<%= number*number %><br>
</body>
</html>