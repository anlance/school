package club.anlan;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

import java.util.Map;

public class CollectAction extends ActionSupport {
    public String execute (){
        Map<String,Object> map =  ActionContext.getContext().getSession();
        String isLogin = (String) map.get("isLogin");
        if(isLogin==null){
            needLogin();
            return "fail";
        }
        else if(isLogin.equals("false")){
            map.put("isLogin","false");
            return "fail";
        }
        else
            return SUCCESS;
    }
    public void needLogin(){

    }
}
