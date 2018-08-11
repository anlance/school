using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class message : System.Web.UI.Page
{
    private int allCount;   //留言总条数
    private int allPage;    //页面总数-1
    private int curPage=0;    //当前页面
    
    protected void Page_Load(object sender, EventArgs e)
    {
        try
        {
            //建立连接
            SqlConnection conn = new SqlConnection();
            conn.ConnectionString = "Server=localhost;uid=sa;pwd=GSSG255211;Database=CXY;";
            String sqlCount = "select count( * ) from guester ";    //查询一共有多少条留言
            SqlCommand cmdCount = new SqlCommand(sqlCount, conn);


            //执行语句
            conn.Open();
            allCount = (int)cmdCount.ExecuteScalar();     //得到总共有多少条留言
            allPage = allCount / 5;
            if (Session["curPage"] == null)
            {
                Session["curPage"] = 0;
                
            }
            curPage = (int)Session["curPage"];
            select(allCount - (curPage * 5));
            conn.Close();
        }
        catch
        {
            Response.Write("连接数据库失败");
        }
    }

    //第一页
    protected void Button1_Click(object sender, EventArgs e)
    {
        Session["curPage"] = 0;
        curPage = (int)Session["curPage"];
        select(allCount - (curPage * 5));
    }

    //上一页
    protected void Button2_Click(object sender, EventArgs e)
    {
        curPage = (int)Session["curPage"];
        if (curPage > 0)
        {
            curPage -= 1;
            Session["curPage"] = curPage;
            select(allCount - (curPage * 5));
        }
    }

    //下一页
    protected void Button3_Click(object sender, EventArgs e)
    {
        curPage = (int)Session["curPage"];
        if (curPage < allPage)
        {
            curPage += 1;
            Session["curPage"] = curPage;
            select(allCount - (curPage * 5));
        }
    }

    //最后页
    protected void Button4_Click(object sender, EventArgs e)
    {
        curPage = allPage;
        Session["curPage"] = curPage;
        select(allCount - (curPage * 5));
    }

    //显示页码为num的页面
    protected void select(int num)
    {
        try
        {
            SqlConnection conn = new SqlConnection();
            conn.ConnectionString = "Server=localhost;uid=sa;pwd=GSSG255211;Database=CXY;";

            int count = 0;
            while (num > 0 && count < 5)
            {

                conn.Open();
                String sql = "select * from guester where id = " + num + ";";    //查询id为num的留言
                SqlCommand command = new SqlCommand(sql, conn);
                SqlDataReader myDataReader = command.ExecuteReader();

                int i = 1;//辅助Label显示

                if (count == 0)
                {
                    while (myDataReader.Read())
                    {
                        DateTime datetime = (DateTime)myDataReader[i + 3];
                        Label1.Text = "访客：" + myDataReader[i].ToString() + "<br>" + "主题：" + myDataReader[i + 1].ToString() + "<br>" + "心情：" + myDataReader[i + 2].ToString() + "<br>" + "时间：" + datetime.ToString("yyyy-MM-dd") + "  " + myDataReader[i + 4].ToString();
                        Label2.Text = " ";
                        Label3.Text = " ";
                        Label4.Text = " ";
                        Label5.Text = " ";
                    }
                }
                else if (count == 1)
                {
                    while (myDataReader.Read())
                    {
                        DateTime datetime = (DateTime)myDataReader[i + 3];
                        Label2.Text = "访客：" + myDataReader[i].ToString() + "<br>" + "主题：" + myDataReader[i + 1].ToString() + "<br>" + "心情：" + myDataReader[i + 2].ToString() + "<br>" + "时间：" + datetime.ToString("yyyy-MM-dd") + "  " + myDataReader[i + 4].ToString();
                        Label3.Text = " ";
                        Label4.Text = " ";
                        Label5.Text = " ";
                    }
                }
                else if (count == 2)
                {
                    while (myDataReader.Read())
                    {
                        DateTime datetime = (DateTime)myDataReader[i + 3];
                        Label3.Text = "访客：" + myDataReader[i].ToString() + "<br>" + "主题：" + myDataReader[i + 1].ToString() + "<br>" + "心情：" + myDataReader[i + 2].ToString() + "<br>" + "时间：" + datetime.ToString("yyyy-MM-dd") + "  " + myDataReader[i + 4].ToString();
                        Label4.Text = " ";
                        Label5.Text = " ";
                    }
                }
                else if (count == 3)
                {
                    while (myDataReader.Read())
                    {
                        DateTime datetime = (DateTime)myDataReader[i + 3];
                        Label4.Text = "访客：" + myDataReader[i].ToString() + "<br>" + "主题：" + myDataReader[i + 1].ToString() + "<br>" + "心情：" + myDataReader[i + 2].ToString() + "<br>" + "时间：" + datetime.ToString("yyyy-MM-dd") + "  " + myDataReader[i + 4].ToString();
                        Label5.Text = " ";
                    }
                }
                else if (count == 4)
                {
                    while (myDataReader.Read())
                    {
                        DateTime datetime = (DateTime)myDataReader[i + 3];
                        Label5.Text = "访客：" + myDataReader[i].ToString() + "<br>" + "主题：" + myDataReader[i + 1].ToString() + "<br>" + "心情：" + myDataReader[i + 2].ToString() + "<br>" + "时间：" + datetime.ToString("yyyy-MM-dd") + "  " + myDataReader[i + 4].ToString();
                    }
                }
                num--;
                count++;
                conn.Close();
            }
            count = 0;
        }
        catch
        {
            Response.Write("连接数据库失败");
        }
    }
}
