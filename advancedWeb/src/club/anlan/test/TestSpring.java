package club.anlan.test;

import club.anlan.beans.Service;
import club.anlan.beans.User;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import service.UserService;

public class TestSpring {
    @Test
    public void testSping1(){
        ApplicationContext context = new ClassPathXmlApplicationContext("applicationContext.xml");
        UserService us = (UserService) context.getBean("service");
        us.printMsg();
        us.persist();
    }
}
