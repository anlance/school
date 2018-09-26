package club.anlan;

import com.opensymphony.xwork2.ActionSupport;


public class LoginAction extends ActionSupport {
    private String name;
    private String age;
    private String pwd;
    private String status;

    public void setName(String name){
        this.name=name;
    }

    public void setPwd(String pwd){
        this.pwd=pwd;
    }

    public void setAge(String age){
        this.age=age;
    }

    public void setStatus(String status){
        this.status = status;
    }

    public String getName(){
        return this.name;
    }

    public String getAge(){
        return this.age;
    }

    public String getPwd(){
        return this.pwd;
    }

    public String getStatus(){
        return this.status;
    }

    /*
    登录 user & admin
     */

    public String user(){
        if(getName().equals(getPwd())){
            System.out.print(getName());
            return "userSuccess";
        }
        else{
            return "fail";
        }
    }

    public String admin(){
        System.out.print(getName()+getPwd());
        if(getName().equals(getPwd())){
//            System.out.print(getName());
            return "adminSuccess";
        }
        else{
            return "fail";
        }
    }

    /*
    验证 user & admin
     */

    public void validateUser(){
        System.out.println("UserAction validateLogin");
        String username = getName();
        String password = getPwd();
//        String str1 = getText();
        if(username==null||username.trim().equals("")){
            this.addFieldError("loginName", getText("accountError1"));
        }
        else if(username.length() < 5 || username.length() > 11){
            this.addFieldError("loginName", getText("accountError2"));
        }
        else if(!username.startsWith("user")){
            this.addFieldError("loginName", getText("accountError3"));
        }else if(password==null || password.trim().equals("")){
            this.addFieldError("loginPassword", getText("pwdError1"));
        }
    }

    public void validateAdmin(){
        System.out.println("AdminAction validateLogin");
        String name = getName();
        String password = getPwd();
        if(name==null||name.trim().equals("")){
            this.addFieldError("loginName", getText("accountError1"));
        }
        else if(name.length() < 6 || name.length() > 10){
            this.addFieldError("loginName", getText("accountError4"));
        }
        else if(!name.startsWith("admin")){
            this.addFieldError("loginName", getText("accountError5"));
        }else if(password==null || password.trim().equals("")){
            this.addFieldError("loginPassword", getText("pwdError1"));
        }
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
