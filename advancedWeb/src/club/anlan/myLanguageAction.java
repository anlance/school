package club.anlan;

import com.opensymphony.xwork2.ActionSupport;

import java.util.Hashtable;
import java.util.Locale;
import java.util.Map;
import java.util.ResourceBundle;

public class myLanguageAction extends ActionSupport {
    private Locale current;

    public void setCurrent(Locale cur){
        this.current=cur;
    }

    public Map getLocales(){
        Map Locales = new Hashtable(2);
        ResourceBundle bundle = ResourceBundle.getBundle("myBaseName", current);
        //美国英语
        Locales.put(bundle.getString("en_US"), Locale.US);
        //简体中文
        Locales.put(bundle.getString("zh_CN"), Locale.CHINA);
        return Locales;
    }

    public String execute(){
        return SUCCESS;
    }
}
