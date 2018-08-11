<%@ Application Language="C#" %>

<script runat="server">

    void Application_Start(object sender, EventArgs e) 
    {
        // 在应用程序启动时运行的代码
        Application["message"]="";//讨论信息
        Application["usercount"]=0;//在线用户人数统计
        Application["username"]="";//在线用户列表
    }
    
    void Application_End(object sender, EventArgs e) 
    {
        //  在应用程序关闭时运行的代码

    }
        
    void Application_Error(object sender, EventArgs e) 
    { 
        // 在出现未处理的错误时运行的代码

    }

    void Session_Start(object sender, EventArgs e) 
    {
        // 在新会话启动时运行的代码
        Session["username"] = "";
        Session.Timeout = 2;
        Application.Lock();
        Application["usercount"]=(int)Application["usercount"]+1;//在线人数+1
        Application.UnLock();
    }

    void Session_End(object sender, EventArgs e) 
    {
        // 在会话结束时运行的代码。 
        // 注意: 只有在 Web.config 文件中的 sessionstate 模式设置为
        // InProc 时，才会引发 Session_End 事件。如果会话模式设置为 StateServer
        // 或 SQLServer，则不引发该事件。
        String str1,str2;
        str1 = Session["username"].ToString();
        Application.Lock();
        Application["usercount"]=(int)Application["usercount"]-1;//在线人数-1
        str2 = Application["username"].ToString();
        Application["username"]=str2.Replace(str1+"\n","");
        Application.UnLock();
        Session.Abandon();
    }
       
</script>
