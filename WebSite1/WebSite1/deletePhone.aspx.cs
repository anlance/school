using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class deletePhone : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        String id = Request.Params["id"];
        try
        {
            //建立连接
            SqlConnection conn = new SqlConnection();
            conn.ConnectionString = "Server=localhost;uid=sa;pwd=GSSG255211;Database=CXY;";
            String sql = "delete  from phone where id = " + id+";";
            SqlCommand command = new SqlCommand(sql, conn);

            //执行语句
            conn.Open();
            int res = command.ExecuteNonQuery();
            conn.Close();
            Response.Redirect("managePhone.aspx");
        }
        catch
        {
            Response.Write("连接数据库失败");
        }
    }
}