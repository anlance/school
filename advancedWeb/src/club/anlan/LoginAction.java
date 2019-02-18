package club.anlan;

import club.anlan.beans.User;
import club.anlan.util.Encrypt;
import club.anlan.util.hbnUtils;
import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;
import org.hibernate.Session;

import java.text.DateFormat;
import java.util.Date;
import java.util.List;
import java.util.Locale;
import java.util.Map;


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
        User user = selectFromDB(1);
        if(user!=null){
            Map<String,Object> map =  ActionContext.getContext().getSession();
            map.put("isLogin","true");
            System.out.println(user.getUsername()+"于"+DateFormat.getDateTimeInstance(DateFormat.LONG, DateFormat.LONG,   Locale.CHINESE).format(new java.util.Date())+"时间登陆系统");
            return "userSuccess";
        }
        else{
            this.addFieldError("loginError", getText("loginError"));
            return "fail";
        }
    }

    public String admin(){
        System.out.println("管理员登录");
        User admin = selectFromDB(0);
        if(admin!=null){
            Map<String,Object> map =  ActionContext.getContext().getSession();
            map.put("isLogin","true");
            return "adminSuccess";
        }
        else{
            this.addFieldError("loginError", getText("loginError"));
            return "fail";
        }
    }

    public User selectFromDB(Integer role) {
        Session session = hbnUtils.getSession();
        try {
            session.beginTransaction();
            String encryptPwd = (new Encrypt(getPwd())).getPwd();
            String sqlTail = " where username=\"" + getName() + "\"and role=" + role + " and password=\"" + encryptPwd+"\"";
            String sqlString = "select * from user" + sqlTail;
            List<User> list = session.createSQLQuery(sqlString).addEntity(User.class).list();
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
