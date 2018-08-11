using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class backStage : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void Button1_Click(object sender, EventArgs e)
    {

        String user = Request.Params["user"];
        String pwd = Request.Params["pwd"];
        if (user.Equals("CXY") && pwd.Equals("051827"))
        {
            Response.Redirect("managePhone.aspx");
        }
        else
        {
            Label1.Text = "帐号或密码错误！";
            Label1.Visible = true;
        }
    }
}