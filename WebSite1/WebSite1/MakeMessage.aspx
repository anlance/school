<%@ Page Language="C#" AutoEventWireup="true" CodeFile="MakeMessage.aspx.cs" Inherits="MakeMessage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body background="image\makeMessage.jpg"style=" background-repeat:no-repeat ;background-size:100% 100%;background-attachment: fixed;">
    <div style="text-align:center;font-size:100px;">
        留言板
    </div>
    <form name="message" runat="server" action="addMessage.aspx" method="post">
       <div style="width:50%">
           <div style="margin-left:150px;margin-top:50px">
            访客：<input style="margin:10px 0px 15px 5px" name="guest" type="text" size="10" /><br/>
             主题：<input  style="margin:10px 0px 15px 5px" name ="theme" type="text" size="15" /><br/>
           </div>
           <div style="margin:10px 0px 15px 150px">
            <table >
                <tr>
                    <td style="margin-top:50px">心情：</td>
                    <td><textarea style="margin:10px 0px 10px 0px" name="mood"rows="10" cols="50"></textarea><br/></td>
                </tr>
            </table>
            <div style="text-align:center;margin-top:10px">
                <input name="submit" type="submit" value="提交留言" />
                <input name ="reset" type="reset" value="全部重写"/>
            </div>
        </div>
       </div>
    </form>
</body>
</html>
