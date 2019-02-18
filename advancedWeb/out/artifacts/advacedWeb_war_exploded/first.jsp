<%--
  Created by IntelliJ IDEA.
  User: anlan
  Date: 2018/12/12
  Time: 21:40
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>首页</title>
</head>
<body>
<div>
    <style>
        #content{
            background-color: rgba(255, 255, 255, 0.95);
            /*width: 280px;*/
            height: auto;
            border: 1px solid #000000;
            border-radius: 6px;
            padding: 10px;
            margin-top: 15%;
            margin-left: auto;
            margin-right: auto;
            /*display: block;*/
            /*margin: auto;*/
            display:inline-block !important;
            text-align: center;
        }
        .errors{
            text-align: center;
            color: red;
            font-size: 10px;
        }
    </style>

    <div id =content>
        <a href="search.action">查询</a><br><br>
        <a href="collect.action">收藏</a>
    </div>
</div>
</body>
</html>
