using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class updatePhone : System.Web.UI.Page
{
    private String id = " ";
    protected void Page_Load(object sender, EventArgs e)
    {
        try
        {
            id = Request.Params["id"];
            //建立连接
            SqlConnection conn = new SqlConnection();
            conn.ConnectionString = "Server=localhost;uid=sa;pwd=GSSG255211;Database=CXY;";
            String sql = "select * from phone where id = "+id+";";
            SqlCommand command = new SqlCommand(sql, conn);

            //执行语句
            conn.Open();

            SqlDataReader myDataReader = command.ExecuteReader();
            int i = 1;
            while (myDataReader.Read())
            {
                name.Value = myDataReader[i].ToString();
                gender.Value = myDataReader[i+1].ToString();
                age.Value = myDataReader[i+2].ToString();
                number.Value = myDataReader[i+3].ToString();
                Email.Value = myDataReader[i+4].ToString();
                info.Value = myDataReader[i+5].ToString();
            }
            
            conn.Close();
            
        }
        catch
        {
            Response.Write("连接数据库失败");
        }
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        //得到输入数据
        String name = Request.Form["name"];
        String gender = Request.Form["gender"];
        String age = Request.Form["age"];
        String number = Request.Form["number"];
        String Email = Request.Form["Email"];
        String info = Request.Form["info"];
        DateTime datetime = DateTime.Now;
        String nowDate = datetime.ToShortDateString();

          //建立连接
         SqlConnection conn = new SqlConnection();
         conn.ConnectionString = "Server=localhost;uid=sa;pwd=GSSG255211;Database=CXY;";
         String sql = "update phone set name='"+name+"',gender='"+gender+"',age='"+age+"',Email='"+Email+"',info='"+info+"',addTime='"+nowDate+"' where id = "+id+";";
         Response.Write(sql);
         SqlCommand command = new SqlCommand(sql, conn);

         //执行插入语句
         conn.Open();
         int RecordsAffectde = command.ExecuteNonQuery();
         conn.Close();

         //重定向
         Response.Redirect("phone.aspx");
    }
}