<%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2018/6/5
  Time: 8:26
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>JSP内置对象_7_1</title>
    </head>
    <body>
        <%
            String addr = request.getRemoteAddr();
        %>
        远程客户端的IP地址：<%=addr %><br>
        <%
            if(addr.startsWith("127.")){
                out.println("访问禁止！");
            }
        %>
    </body>
</html>
