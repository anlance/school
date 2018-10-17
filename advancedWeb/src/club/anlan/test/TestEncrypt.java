package club.anlan.test;

import club.anlan.util.Encrypt;
import org.junit.Test;

public class TestEncrypt {

    @Test
    public void test1(){
        String test = "aazzcdefg123490AZ";
        System.out.print("通过方法加密：");
        Encrypt et = new Encrypt();
        String abc = et.encrypt("aazzcdefg123490AZ");
        System.out.println(abc);
        System.out.print("通过对象加密:");
        String abc2 = (new Encrypt(test)).getPwd();
        System.out.println(abc2);
    }
}
