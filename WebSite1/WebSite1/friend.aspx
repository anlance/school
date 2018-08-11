<%@ Page Language="C#" AutoEventWireup="true" CodeFile="friend.aspx.cs" Inherits="friend" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body style="background-color:wheat">
            <form id="form1" runat="server">
            <div style="height:auto;margin-left:50px;margin-right:50px;margin-top:50px;height:20px">
                   请输入你要查找的姓名：<input name="name" type="text" size="20"/>
                <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="确定"  CssClass="myButton"/>
                <span style="float:right">[<a href="main.aspx">返回主页</a>]</span>
              </div>
              </form>
        <hr align="center" size="1" />
        <div>
           <div style="text-align:left;background-color:coral;height:25px;"><asp:Label ID="Label" runat="server" Text=" " Visible="true"></asp:Label></div>
        </div>
               
</body>
</html>
