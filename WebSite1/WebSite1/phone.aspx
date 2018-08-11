<%@ Page Language="C#" AutoEventWireup="true" CodeFile="phone.aspx.cs" Inherits="phone" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body style="background-color:wheat">
            <form id="form1" runat="server">
            <div style="height:auto;margin-left:50px;margin-right:50px;margin-top:50px;height:20px">
                   <span style="float:left">[<a href="makePhone.aspx">添加记录</a>]</span>
                   <span style="float:right">[<a href="main.aspx">返回主页</a>]</span>
              </div>           
        <hr align="center" size="1" />
        <div>
           <div style="text-align:left;background-color:coral;height:25px;"><asp:Label ID="Label" runat="server" Text=" " Visible="true"></asp:Label></div>
        </div>
                <div style="text-align:center;margin-top:25px;">
                   
                </div>
                
            </form>
</body>
</html>
