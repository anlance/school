package club.anlan.test;

import org.apache.log4j.Level;
import org.apache.log4j.Logger;
import org.apache.log4j.PropertyConfigurator;

public class LogUtil {
    private Logger logger = Logger.getLogger(TestLog4j.class);
    static String strConfigure = "C:\\Users\\anlan\\IdeaProjects\\advancedWeb\\log4j.properties";
    public LogUtil(){

    }

    public LogUtil(Class c){
        logger = Logger.getLogger(c);
        PropertyConfigurator.configure(strConfigure);
    }
    public Logger getLogger(){
        return logger;
    }
}
