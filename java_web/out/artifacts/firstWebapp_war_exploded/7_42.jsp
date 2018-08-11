<%@ page import="java.util.ArrayList" %><%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2018/6/6
  Time: 21:53
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java"  %>
<html>
    <head>
        <title>jsp内置对象_7_42</title>
    </head>
    <body>
    <form>
        <%
            ArrayList books = (ArrayList)session.getAttribute("books");
            if(books==null){
                books = new ArrayList();
                session.setAttribute("books",books);
            }
            String book = request.getParameter("info");
            if(book!=null){
                book = new String(book.getBytes("iso-8859-1"),"utf-8");
                books.add(book);
            }
        %>
        <table>
            <tr client="center">计算机书籍</tr>
            <tr>
                <th>书名</th>
                <th>价格</th>
            </tr>
            <tr>
                <td>Python神经网络编程</td>
                <td>57元</td>
                <td><a href ="7_42.jsp?info=Python神经网络编程,价格57元">购买</a></td>
            </tr>
            <tr>
                <td>Web安全防护指南</td>
                <td>62元</td>
                <td><a href ="7_42.jsp?info=Web安全防护指南,价格62元">购买</a></td>
            </tr>
            <tr>
                <td>Web安全之强化学习</td>
                <td>60元</td>
                <td><a href ="7_42.jsp?info=Web安全之强化学习,价格60元">购买</a></td>
            </tr>
            <tr>
                <td>Spring微服务实战</td>
                <td>65元</td>
                <td><a href ="7_42.jsp?info=Spring微服务实战,价格65元">购买</a></td>
            </tr>
        </table>
        <a href="7_41.jsp">历史书籍</a><br>
        <a href="7_43.jsp">显示购物车</a>
    </form>
    </body>
</html>
