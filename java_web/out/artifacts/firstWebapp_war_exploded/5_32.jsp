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
        <title>Title</title>
    </head>
    <body>
        <%
            String account = request.getParameter("account");
            String password = request.getParameter("password");
            if(!account.equals(password)){
                out.println("登陆失败！");
        %>
        <br><a href="5_31.jsp">返回登录页面</a>
        <%
            }else{
                out.println("登陆成功");
        %>
            <form action="5_33.jsp" method="post">
                <input name="account1" type="hidden" value="<%= account %>">
                输入用户姓名：<input name="name" type="text" ><br>
        <%
            for(int i=0;i<3;i++){
        %>
        电话号码<%=i+1 %>:<input name="phoneNumber" type="text"><br>
        <%
            }
        %>
                <input type="submit" value="输入信息">
            </form>
        <%
            }
        %>

    </body>
</html>
