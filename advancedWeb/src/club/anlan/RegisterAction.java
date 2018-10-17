package club.anlan;

import club.anlan.beans.Student;
import club.anlan.util.Encrypt;
import com.opensymphony.xwork2.ActionSupport;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

import java.util.regex.Pattern;

public class RegisterAction extends ActionSupport {
    private Student student;
    private String rePassword;

    public String getRePassword() {
        return rePassword;
    }

    public void setRePassword(String rePassword) {
        this.rePassword = rePassword;
    }

    public Student getStudent() {
        return student;
    }

    public void setStudent(Student student) {
        this.student = student;
    }


    public String userRegister(){
        student.setRole(1);
        System.out.println("注册用户");
        return saveToDB(student);
    }

    public String adminRegister(){
        student.setRole(0);
        System.out.println("注册管理员");
        return saveToDB(student);
    }

    //进入注册页面
    public String toRegister(){
        return "fail";
    }

    public String saveToDB(Student student) {
        //加密
        String encryptPwd = (new Encrypt(student.getPassword())).getPwd();
        student.setPassword(encryptPwd);

        Configuration configure = new Configuration().configure();
        SessionFactory sessionFactory = configure.buildSessionFactory();
        Session session = sessionFactory.getCurrentSession();

        try {
            session.beginTransaction();
            session.save(student);
            session.getTransaction().commit();
        } catch (Exception e) {
            e.printStackTrace();
            session.getTransaction().rollback();
            System.out.println("注册失败");
            return "fail";
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
        if(student.getUsername()==null||student.getUsername().trim().equals("")){
            this.addFieldError("registerError", getText("accountError1"));
        } else if(student.getAge()==null || student.getAge().equals("")){
            this.addFieldError("registerError", getText("accountError2"));
        } else if(student.getAge()<12 || student.getAge()>100){
            this.addFieldError("registerError", getText("accountError3"));
        } else if(!student.getPassword().equals(getRePassword())){
            this.addFieldError("registerError", getText("accountError4"));
        } else if(Pattern.matches("[a-zA-Z0-9]{5,12}", student.getPassword())==false){
            this.addFieldError("registerError", getText("accountError5"));
        }
    }
}
