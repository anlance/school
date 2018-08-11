using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class managePhone : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        try
        {
            //建立连接
            SqlConnection conn = new SqlConnection();
            conn.ConnectionString = "Server=localhost;uid=sa;pwd=GSSG255211;Database=CXY;";
            String sql = "select * from phone where id > 0 order by id desc;";
            SqlCommand command = new SqlCommand(sql, conn);

            //执行语句
            conn.Open();

            SqlDataReader myDataReader = command.ExecuteReader();
            String str = "<table align='center'><tr><th>姓名</th><th>性别</th><th>年龄</th><th>电话</th><th>E-mail</th><th>简介</th><th>添加日期</th><th>删除</th><th>更新</th></tr>";
            int i = 1;
            while (myDataReader.Read())
            {
                DateTime datetime = (DateTime)myDataReader[7];
                String id = myDataReader[i - 1].ToString();
                str += ("<tr><td>" + myDataReader[i].ToString() + "</td><td>" + myDataReader[i + 1].ToString() + "</td><td>" + myDataReader[i + 2].ToString() + "</td><td>" + myDataReader[i + 3].ToString() + "</td><td>" + myDataReader[i + 4].ToString() + "</td><td>" + myDataReader[i + 5].ToString() + "</td><td>" + datetime.ToString("yyyy-MM-dd") + "</td><td><a href='deletePhone.aspx?id="+ id+"'>删除</a></td><td><a href='updatePhone.aspx?id="+id+"'>更新</a></td></tr>");
            }
            str += "</table>";
            conn.Close();
            Label.Text = str;
        }
        catch
        {
            Response.Write("连接数据库失败");
        }

    }
}