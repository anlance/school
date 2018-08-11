<%@ page import="java.util.ArrayList" %><%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2018/6/6
  Time: 22:52
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java"  %>
<html>
    <head>
        <title>jsp内置对象_7_43</title>
    </head>
    <body>
    <%
        ArrayList books = (ArrayList)session.getAttribute("books");
        if(books==null){
            books = new ArrayList();
            session.setAttribute("books",books);
        }
        String book=request.getParameter("info");

        if(books.size()!=0){
            if(book!=null){
                book = new String(book.getBytes("iso-8859-1"),"utf-8");
                for(int i=0;i<books.size();i++){
                    String tempBook=(String)books.get(i);
                    if(book.equals(tempBook)){
                        books.remove(i);
                        break;
                    }
                }
            }
            if(books.size()!=0){
                out.write("购物车中的内容：<br>");
                for(int i=0;i<books.size();i++){
                    out.write(books.get(i).toString());
                    out.write("<a href='7_43.jsp?info="+books.get(i).toString()+"'>删除</a><br>");
                }
            }
            else{
                out.write("购物车是空的<br>");
            }
        }
        else{
            out.write("购物车是空的<br>");
        }
    %>
    <a href="7_41.jsp">历史书籍</a><br>
    <a href="7_42.jsp">计算机书籍</a><br>
    </body>
</html>
