<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<html>
<head>
	第四章第二题<br><br>
</head>
<body>
	<%
		for(int i=1;i<10;i++){
	 %>
	 <a href = "link2.jsp?n=<%= i  %>"><%= i %></a><br>
	 <%
	 	}
	  %>
</body>
</html>