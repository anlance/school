using System;
using System.Data.SqlClient;

public partial class addMessage : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
             //得到输入数据
            String guest = Request.Form["guest"];
            String theme = Request.Form["theme"];
            String mood = Request.Form["mood"];
            DateTime datetime = DateTime.Now;
            String nowDate = datetime.ToShortDateString();
            String nowTime = datetime.ToShortTimeString();
            
            //建立连接
            SqlConnection conn = new SqlConnection();
            conn.ConnectionString = "Server=localhost;uid=sa;pwd=GSSG255211;Database=CXY;";
            String sql = "insert into guester(name,theme,mood,nowDate,nowTime) values('" + guest + "','" + theme + "','" + mood + "','" + nowDate + "','" + nowTime + "');";
            SqlCommand command = new SqlCommand(sql, conn);
            
            //执行插入语句
            conn.Open();
            int RecordsAffectde = command.ExecuteNonQuery();
            conn.Close();

             //重定向
            Response.Redirect("message.aspx");



    }
}