<%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2018/6/1
  Time: 13:37
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>Login</title>
    </head>
    <body>
    这是一个登录表单，如果输入的账号密码相等，将显示登陆成功，否则显示登录失败<br>
        <form name="loginForm" action="5_22.jsp" method="post">
            请输入账号：<input name="account" type="text"><br>
            请输入密码：<input name="password" type="password"><br>
            是否为VIP会员：<input name ="isVIP" type="radio" value="not" checked>不是
                    <input name ="isVIP" type="radio" value="is">是<br>
                    <input name="VIPid" type="hidden" value="0000">
            <input type="button" value="登录" onclick="login()">
        </form>
        <script type="text/javascript">
            function login(){
                if(document.loginForm.isVIP.value == "is"){
                    var vipID = window.prompt("请输入会员编号的后四位");
                    document.loginForm.VIPid.value = vipID;
                }
                loginForm.submit();
            }

        </script>
    </body>
</html>
