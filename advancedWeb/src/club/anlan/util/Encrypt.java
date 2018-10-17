package club.anlan.util;

public class Encrypt {
    private String pwd;

    //输入只能为0-9 a-z A-Z         输出为 ascii码表 33-126 的字符

    public Encrypt(){

    }

    public Encrypt(String pwd){
        this.pwd=encrypt(pwd);
    }

    public String getPwd() {
        return pwd;
    }

    public void setPwd(String pwd) {
        this.pwd=encrypt(pwd);
    }

    public String encrypt(String pwd){
        char[] cPwd = pwd.toCharArray();
        int addIndex = 9;
        for(int i=0;i<pwd.length();i++){
            char temp = cPwd[i];
            addIndex = (addIndex+9)%127;
            int index = (int) temp;
            index = (index+addIndex)%127;
            while(index<33){
                index += 9;
            }
            cPwd[i] = (char) index;
        }
        return String.valueOf(cPwd);
    }
}
