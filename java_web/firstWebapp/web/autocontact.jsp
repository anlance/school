<%@page import="java.util.Date"%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%  
String path = request.getContextPath();  
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";  
request.setAttribute("path", basePath); 
request.setCharacterEncoding("UTF-8");
%> 
<%--<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>--%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>人工服务</title>
</head>
<body>
    <div id="top" style="display: flex;font-size: 20px">
        <div style="width: 500px;">
            <span style="margin-left: 200px">用户名:${username }</span>&nbsp;&nbsp;&nbsp;&nbsp;
            <span>消息</span>

        </div>
        <div style="margin-left: 600px; width: 40%;">
  
            <a href="login.jsp" >登录</a>|
            <a href="regist.jsp" >注册</a>
        </div>
    </div>
    <div style="background-image:url(${pageContext.request.contextPath }/bg.jpg) ;background-size: 120% 100%;">
        <div id="logo">
            <img alt="logo" src="${pageContext.request.contextPath }/logo2.jpg" style="width: 60px;height: 60px;margin-left: 200px">
            <span style="font-size: 25px">|服务中心</span>
            <span style="margin-left:700px;font-size: 20px;color: darkturquoise">在线客服</span>
        </div>
        <div id="show">
        	<%
        		Date d = new Date();
        		String s1 = d.toLocaleString();
        		request.setAttribute("d",s1 );
        		//String idea = request.getAttribute("s");

        		String s2 = request.getParameter("info");
        		request.setAttribute("a",s2 );
        	 %>
           	<div id="showcontact" style="width: 900px;height: 500px;margin-left: 400px;margin-top: 30px;border: 2px solid blueviolet" >
	           <c:if test="${question != null }"><span style="margin-left: 550px">${d }${question }</span></c:if>		
	           <br>
	           <span style="margin-left: 20px;">${a }</span>	
           	</div>
        </div>
            <form action="club/anlan/ser"method="post" >
                <span style="margin-left: 900px">请输入您的问题:</span>
                <input type="text" name="idea" style="width: 170px;height: 18px;margin-left: 10px" />
                <input type="submit" value="发送">
            </form>
        </div>
    </div>
</body>
</html>