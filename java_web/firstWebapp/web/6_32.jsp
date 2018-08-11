<%@ page import="java.sql.Connection" %>
<%@ page import="java.sql.DriverManager" %>
<%@ page import="java.sql.Statement" %>
<%@ page import="java.sql.ResultSet" %><%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2018/6/1
  Time: 20:29
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>6_32_result</title>
    </head>
    <body>
    <%
        Class.forName("com.mysql.jdbc.Driver");
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/school","root","255211");
        Statement stat = conn.createStatement();
        String stuNo = request.getParameter("stuId");
        String stuName = request.getParameter("stuName");
        String sql = "select STUNO,STUNAME from T_STUDENT";
        ResultSet rs = stat.executeQuery(sql);
        boolean judge = false;
        while(rs.next()){
            String stuno = rs.getString("STUNO");
            String  stuname = rs.getString("STUNAME");
            if(stuNo.equals(stuno)&&stuName.equals(stuname)){
                judge=true;
                break;
            }
        }
        if(judge){
            out.write("登录成功！");
        }else{
            out.write("登录失败！");
        }
        conn.close();
        stat.close();
    %>
    </body>
</html>
