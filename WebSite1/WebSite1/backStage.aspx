<%@ Page Language="C#" AutoEventWireup="true" CodeFile="backStage.aspx.cs" Inherits="backStage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body style="background-color:lightgreen">
    <form id="form1" runat="server">
        <div style="text-align:center">
            <div style="margin-top:100px;margin-bottom:100px;font-size:50px;color:dodgerblue">管理员登录</div>
           <div style="margin-top:10px;margin-bottom:10px"> 账号：<input type="text" name="user" size="20" /></div>
            <div style="margin-top:10px;margin-bottom:10px">密码：<input type="password" name="pwd" size="20"/></div>
            <div style="margin-top:20px;margin-bottom:10px"><asp:Button ID="Button1" runat="server" Text="登录" Width="80" OnClick="Button1_Click" /></div>
             <div style="margin-top:20px;margin-bottom:10px"><asp:Label ID="Label1" runat="server" Text="Label" Visible="false"  BackColor="Yellow"></asp:Label></div>
        </div>
    </form>
</body>
</html>
