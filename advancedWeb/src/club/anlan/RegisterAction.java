package club.anlan;

import club.anlan.beans.User;
import club.anlan.util.Encrypt;
import club.anlan.util.hbnUtils;
import com.opensymphony.xwork2.ActionSupport;
import org.hibernate.Session;

import java.util.regex.Pattern;

public class RegisterAction extends ActionSupport {
    private User user;
    private String rePassword;

    public String getRePassword() {
        return rePassword;
    }

    public void setRePassword(String rePassword) {
        this.rePassword = rePassword;
    }

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }


    public String userRegister(){
        user.setRole(1);
        System.out.println("注册用户");
        return saveToDB(user);
    }

    public String adminRegister(){
        user.setRole(0);
        System.out.println("注册管理员");
        return saveToDB(user);
    }

    //进入注册页面
    public String toRegister(){
        return "fail";
    }

    public String saveToDB(User user) {
        //加密
        String encryptPwd = (new Encrypt(user.getPassword())).getPwd();
        user.setPassword(encryptPwd);

        Session session = hbnUtils.getSession();

        try {
            session.beginTransaction();
            session.save(user);
            session.getTransaction().commit();
        } catch (Exception e) {
            e.printStackTrace();
            session.getTransaction().rollback();
        }
        System.out.println("注册成功");
        this.addFieldError("RegisterSuccess", getText("RegisterSuccess"));
        return "success";
    }

    //验证
    public void validateUserRegister(){
        System.out.println("用户注册验证");
        myValidate();

    }

    public void validateAdminRegister(){
        System.out.println("管理员注册验证");
        myValidate();
    }

    public void myValidate(){
        if(user.getUsername()==null||user.getUsername().trim().equals("")){
            this.addFieldError("registerError", getText("accountError1"));
        } else if(user.getAge()==null || user.getAge().equals("")){
            this.addFieldError("registerError", getText("accountError2"));
        } else if(user.getAge()<12 || user.getAge()>100){
            this.addFieldError("registerError", getText("accountError3"));
        } else if(!user.getPassword().equals(getRePassword())){
            this.addFieldError("registerError", getText("accountError4"));
        } else if(Pattern.matches("[a-zA-Z0-9]{5,12}", user.getPassword())==false){
            this.addFieldError("registerError", getText("accountError5"));
        }
    }
}
