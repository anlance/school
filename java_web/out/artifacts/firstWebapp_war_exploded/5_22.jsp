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
            String isVIP = request.getParameter("isVIP");
            if(!account.equals(password)){
                out.println("登陆失败！");
            }else if(isVIP.equals("is")) {
                String VIPid = request.getParameter("VIPid");
                out.println("登录成功。VIP会员" + VIPid + "，欢迎您回来！");
            }else{
                out.println("登陆成功");
            }
        %>
    </body>
</html>
