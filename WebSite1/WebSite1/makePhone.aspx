<%@ Page Language="C#" AutoEventWireup="true" CodeFile="makePhone.aspx.cs" Inherits="makePhone" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body background="image\makeMessage.jpg"style=" background-repeat:no-repeat ;background-size:100% 100%;background-attachment: fixed;">
    <div style="text-align:center;font-size:50px;">
        添加新纪录
    </div>
    <div style="text-align:center;font-size:10px;">
        其中带*号的必填
    </div>
    <form name="message" runat="server" action="addPhone.aspx" method="post">
       <div style="width:50%">
           <div style="margin-left:150px;margin-top:15px">
             姓名：<input style="margin:10px 5px 15px 5px" name="name" type="text" size="10" />*<br/>
             性别：<input  style="margin:10px 5px 15px 5px" name ="gender" type="text" size="1" /><br/>
             年龄：<input  style="margin:10px 5px 15px 5px" name ="age" type="text" size="2" /><br/>
             电话：<input  style="margin:10px 5px 15px 5px" name ="number" type="text" size="10" />*<br/>
           </div>
            <div style="margin-left:140px;">
             E-mail：<input  style="margin:10px 0px 15px 0px" name ="Email" type="text" size="15" /><br/>
           </div>
           <div style="margin:10px 0px 15px 150px">
            <table >
                <tr>
                    <td style="margin-top:50px">简介：</td>
                    <td><textarea style="margin:10px 0px 10px 0px" name="info"rows="10" cols="50"></textarea><br/></td>
                </tr>
            </table>
            <div style="text-align:center;margin-top:10px">
                <input name="submit" type="submit" value="全部确定" />
                <input name ="reset" type="reset" value="全部重写"/>
            </div>
        </div>
       </div>
    </form>
</body>
</html>
