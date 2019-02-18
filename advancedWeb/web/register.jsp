<%@ taglib prefix="S" uri="/struts-tags" %>
<%--
  Created by IntelliJ IDEA.
  User: anlan
  Date: 2018/9/29
  Time: 14:47
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>login</title>
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
    <script>
        function changeTarget() {
            var status = document.getElementById("status").value;
            var form = document.getElementById("register");
            form.action = "register_"+status+"Register.action";
            form.submit();
        }
    </script>
</head>
<body bgcolor="#8fbc8f" style="text-align: center">
<div id =content>
    <S:form id = "register" action="register_*" method="post" style="padding: 2px;line-height: 25px; text-align:center">
        <S:textfield name="user.username" key="index.form.name"/>
        <S:textfield name="user.age" key="index.form.age"/>
        <S:password name="user.password" key="index.form.password"/>
        <S:password name="rePassword" key="index.form.rePassword"/>
    </S:form>
    <S:if test="%{fieldErrors['loginError'][0]!=null}">
        <span class="errors">${fieldErrors['registerError'][0]}</span><br><br>
    </S:if>
    <select id="status" name ="status">
        <option value ="user"><S:text name="index.form.status.user"/></option>
        <option value ="admin"><S:text name="index.form.status.admin"/></option>
    </select>
    <button name="register"  onclick="changeTarget()" style="text-align: center" ><S:text name="register.form.submit"/></button><br><br>
</div>
</body>
</html>
