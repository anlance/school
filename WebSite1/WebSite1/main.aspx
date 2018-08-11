<%@ Page Language="C#" AutoEventWireup="true" CodeFile="main.aspx.cs" Inherits="main" %>

<!DOCTYPE html>

<html>
    <head runat="server">
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
        <link type="text/css" rel="stylesheet" href='styleSheet/myStyleSheet.css'/>
    </head>
   <body>

       <div style="border-style:dashed;border-width:1px;height:170px">
        <table border="0">
            <tr>
                <td style="width:300px;">
                    <img src="image/welcome1.jpg" alt="welcome1" width="160" height="160" />
                </td>
                <td style="width:800px">
                        <div style="height:40px;text-align:center">
                            欢迎来到我的主页！
                        </div>
                        <div style="height:auto;text-align:justify;text-align-last:justify;width:750px;margin-left:30px;margin-right:50px">
                           <a href="message.aspx"><img src="image/message.png" alt="留言板" width="40" height="40" /></a>
                           <a href="phone.aspx"><img src="image/phone.png" alt="通讯录" width="40" height="40" /></a>
                           <a href="school.aspx"><img src="image/school.png" alt="校园论坛" width="40" height="40" /></a>
                           <a href="friend.aspx"><img src="image/friend.png" alt="寻找朋友" width="40" height="40" /></a>
                           <a href="backStage.aspx"><img src="image/backStage.png" alt="后台管理" width="40" height="40" /></a>
                        </div>
                         <div style="height:auto;text-align:justify;text-align-last:justify">
                           <a href="message.aspx" >留言板</a>
                           <a href="phone.aspx ">通讯录</a>
                           <a href="school.aspx">校园论坛</a>
                           <a href="friend.aspx">寻找朋友</a>
                           <a href="backStage.aspx">后台管理</a>
                        </div>
                </td>
                <td style="width:200px"></td>
                <td style="width:100px">
                    <img src="image/welcome.jpg" alt="welcome" width="100" height="160" />
                </td>
            </tr>
    </table>
    </div>

       <div style="height:20px"></div>

       <!---左下--->
       <div style="border-style:dashed;width:49%;float:left;border-width:2px;border-color:seagreen">
            <div class="div1">
                <span style="float:left">>>社区精华</span>
                <span style="float:right"><a href="moreCommunity.aspx">More</a>>></span>
            </div>
            <div style="border-style:double">
                <img src="image/library.jpg" alt="成都理工大学新图书馆" width="210"  height="210"/>
                <p style="float:right;text-align:left">
                    清晨阳光下的图书馆，是那么的美丽！快起来一起学习吧！
                </p>
            </div>
            <div style="border-style:double">
                <ul>
                    <li>[每日娱乐] 最冷世界杯！德国输了，巴西平了，葡萄牙平了.....</li>
                    <li>[明日之星]  李青：控制自己，掌控敌人。</li>
                    <li>[大学生活]  今天的你羡慕高中的你吗</li>
                    <li>[理工之声]  成都理工大学关于2018年“专升本”拟录取名单公示</li>
                </ul>
            </div>
        </div>
        
       <!---右下--->
       <div style="border-style:dashed;width:49%;float:right;border-width:2px;border-color:seagreen">
            <div class="div1">
                <span style="float:left">>>日志精华</span>
                <span style="float:right"><a href="moreCommunity.aspx">More</a>>></span>
            </div>
            <div style="border-style:double">
                <img src="image/monster.PNG" alt="侏罗纪世界2" width="350"  height="210"/>
                <p style="float:right;text-align:left">
                    生命不能被控制<br/>
                    生命会挣脱枷锁<br/>
                    生命总会找到出路<br />
                </p>
            </div>
            <div style="border-style:double">
                <ul>
                    <li>做这12件事，你的生活将充满乐趣.....</li>
                    <li>20多岁，你着什么急.......</li>
                    <li>有什么事情，和读书一样值得终生坚持做.....</li>
                    <li>我看到了人生的另一种可能......</li>
                </ul>
            </div>
        </div>

   </body>
</html>
