<%@ page import="java.sql.Connection" %>
<%@ page import="java.sql.Statement" %>
<%@ page import="java.sql.DriverManager" %>
<%@ page import="java.sql.ResultSet" %><%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2018/6/1
  Time: 20:06
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>6_22数据库</title>
    </head>
    <body>
    <%
        Class.forName("com.mysql.jdbc.Driver");
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/school","root","255211");
        Statement stat = conn.createStatement();
        String name = request.getParameter("select");
        String sql = "select * from T_STUDENT where STUNAME LIKE '%"+name+"%'";
        ResultSet rs = stat.executeQuery(sql);
        out.write("STUNO    STUNAME    STUSEX<br>");
        while(rs.next()){
            String stuno = rs.getString("STUNO");
            String  stuname = rs.getString("STUNAME");
            String stusex = rs.getString("STUSEX");
            out.write(stuno+"  "+stuname+" "+stusex+"<br>");
        }
        conn.close();
        stat.close();
    %>
    </body>
</html>
