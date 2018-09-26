<%@ taglib prefix="S" uri="/struts-tags" %>
<%--
  Created by IntelliJ IDEA.
  User: anlan
  Date: 2018/9/6
  Time: 17:48
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
              var form = document.getElementById("login");
              //方法三
              form.action = "login_"+status+".action";
              // 方法二
              // form.action = "login!"+status+".action";
              form.submit();
          }
      </script>
  </head>
  <body bgcolor="#8fbc8f" style="text-align: center">
    <div>
        <a href = "myLanguage.action?request_locale=zh_CN">中文</a>
        <a href = "myLanguage.action?request_locale=en_US">english</a>
    </div>
    <div id =content>
        <S:form id = "login" action="login_*" method="post" style="padding: 2px;line-height: 25px">
            <S:textfield name="name" key="index.form.name"/>
            <S:textfield name="age" key="index.form.age"/>
            <S:password name="pwd" key="index.form.password"/>
            <%--<input type="button" name="login"  onclick="changeTarget()" style="text-align: center">--%>
            <%--<input type="submit" name="login" value="登陆" style="text-align: center">--%>
        </S:form>
        <S:if test="%{fieldErrors['loginName'][0]!=null}">
            <span class="errors">${fieldErrors['loginName'][0]}</span><br><br>
        </S:if>
        <S:if test="%{fieldErrors['loginPassword'][0]!=null}">
            <span class="errors">${fieldErrors['loginPassword'][0]}</span><br><br>
        </S:if>
        <select id="status" name ="status">
            <option value ="user"><S:text name="index.form.status.user"/></option>
            <option value ="admin"><S:text name="index.form.status.admin"/></option>
        </select>
        <button name="login"  onclick="changeTarget()" style="text-align: center" ><S:text name="index.form.login"/></button>
    </div>
  </body>
</html>
