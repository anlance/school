package club.anlan;

import club.anlan.beans.Student;
import club.anlan.util.Encrypt;
import com.opensymphony.xwork2.ActionSupport;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

import java.util.List;


public class LoginAction extends ActionSupport {
    private String name;
    private String pwd;

    public void setName(String name){
        this.name=name;
    }

    public void setPwd(String pwd){
        this.pwd=pwd;
    }

    public String getName(){
        return this.name;
    }

    public String getPwd(){
        return this.pwd;
    }

    /*
    登录 user & admin
     */

    public String user(){
        System.out.println("用户登录");
        Student user = selectFromDB(1);
        if(user!=null){
            return "userSuccess";
        }
        else{
            this.addFieldError("loginError", getText("loginError"));
            return "fail";
        }
    }

    public String admin(){
        System.out.println("管理员登录");
        Student admin = selectFromDB(0);
        if(admin!=null){
            return "adminSuccess";
        }
        else{
            this.addFieldError("loginError", getText("loginError"));
            return "fail";
        }
    }

    public Student selectFromDB(Integer role) {
        Configuration configure = new Configuration().configure();
        SessionFactory sessionFactory = configure.buildSessionFactory();
        Session session = sessionFactory.getCurrentSession();
        try {
            session.beginTransaction();
            String encryptPwd = (new Encrypt(getPwd())).getPwd();
            String sqlTail = " where tusername=\"" + getName() + "\"and trole=" + role + " and tpassword=\"" + encryptPwd+"\"";
            String sqlString = "select * from student" + sqlTail;
            List<Student> list = session.createSQLQuery(sqlString).addEntity(Student.class).list();
            session.getTransaction().commit();
            if(list.isEmpty()){
                return null;
            }
            return list.get(0);
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
            session.getTransaction().rollback();
        }
        return null;
    }


//    方法一
//    public String execute (){
//        if(this.user.equals(this.pwd)){
//            if(this.status.equals("admin")){
//                return "adminSuccess";
//            }else{
//                return "userSuccess";
//            }
//        }
//        else{
//            return "fail";
//        }
//    }
}
