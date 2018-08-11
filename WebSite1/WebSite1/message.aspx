<%@ Page Language="C#" AutoEventWireup="true" CodeFile="message.aspx.cs" Inherits="message" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>留言板</title>
    <style>
        .mylable{
            margin-left:50px;
        }
        .myButton{
            margin-left:15px;
            margin-right:15px;
        }
     </style>
</head>
<body style="background-color:lightblue">
            <form id="form1" runat="server">
            <div style="height:auto;margin-left:50px;margin-right:50px;margin-top:50px;height:20px">
                   <span style="float:left">[<a href="MakeMessage.aspx">我要留言</a>]</span>
                   <span style="float:right">[<a href="main.aspx">返回主页</a>]</span>
              </div>           
        <hr align="center" size="1" />
        <div>
            <div style="text-align:left;background-color:lightgreen;height:95px;"><asp:Label ID="Label1" runat="server" Text=" " Visible="true"></asp:Label></div>
            <div style="text-align:left;background-color:coral;height:95px;"><asp:Label ID="Label2" runat="server" Text=" " Visible="true"></asp:Label></div>
            <div style="text-align:left;background-color:cornsilk;height:95px;"><asp:Label ID="Label3" runat="server" Text=" " Visible="true"></asp:Label></div>
            <div style="text-align:left;background-color:gold;height:95px;"><asp:Label ID="Label4" runat="server" Text=" " Visible="true"></asp:Label></div>
           <div style="text-align:left;background-color:mediumorchid;height:95px;"><asp:Label ID="Label5" runat="server" Text=" " Visible="true"></asp:Label></div>
        </div>
                <div style="text-align:center;margin-top:25px;">
                    <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="第一页"  CssClass="myButton"/>
                    <asp:Button ID="Button2" runat="server" OnClick="Button2_Click" Text="上一页"  CssClass="myButton"/>
                    <asp:Button ID="Button3" runat="server" OnClick="Button3_Click" Text="下一页"  CssClass="myButton"/>
                    <asp:Button ID="Button4" runat="server" OnClick="Button4_Click" Text="最后页"  CssClass="myButton"/>
                </div>
                
            </form>
</body>
</html>
