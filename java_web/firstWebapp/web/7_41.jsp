<%@ page import="java.util.ArrayList" %><%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2018/6/6
  Time: 21:52
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java"  %>
<html>
    <head>
        <title>jsp内置对象_7_41</title>
    </head>
    <body>
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
        <form>
            <table>
                <tr client="center">历史书籍</tr>
                <tr>
                    <th>书名</th>
                    <th>价格</th>
                </tr>
                <tr>
                    <td>中国大历史</td>
                    <td>22元</td>
                    <td><a href ="7_41.jsp?info=中国大历史,价格30元">购买</a></td>
                </tr>
                <tr>
                    <td>联合与斗争</td>
                    <td>36元</td>
                    <td><a href ="7_41.jsp?info=联合与斗争,价格36元">购买</a></td>
                </tr>
                <tr>
                    <td>资治通鉴(全四册)</td>
                    <td>92元</td>
                    <td><a href ="7_41.jsp?info=资治通鉴(全四册),价格92元">购买</a></td>
                </tr>
                <tr>
                    <td>大英博物馆世界简史</td>
                    <td>140元</td>
                    <td><a href ="7_41.jsp?info=大英博物馆世界简史,价格140元">购买</a></td>
                </tr>
            </table>
            <a href="7_42.jsp">计算机书籍</a><br>
            <a href="7_43.jsp">显示购物车</a>
        </form>
    </body>
</html>
