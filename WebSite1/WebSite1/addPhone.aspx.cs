using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class addPhone : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
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
        String sql = "insert into phone(name,gender,age,number,Email,info,addTime) values('" + name + "','" + gender + "','" + age + "','" + number + "','" + Email + "','" + info + "','" + nowDate + "');";
        SqlCommand command = new SqlCommand(sql, conn);

        //执行插入语句
        conn.Open();
        int RecordsAffectde = command.ExecuteNonQuery();
        conn.Close();

        //重定向
        Response.Redirect("phone.aspx");
    }
}