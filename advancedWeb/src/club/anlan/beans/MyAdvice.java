package club.anlan.beans;

import java.lang.reflect.Method;
import java.util.Date;

import org.springframework.aop.AfterReturningAdvice;
import org.springframework.aop.MethodBeforeAdvice;

public class MyAdvice {
	public void afterAdvice(){
		System.out.println("需要登录才能进行收藏操作");
	}

	public void afterReturningAdvice(){
	    Date date = new Date();
	    System.out.println("于"+date.getTime()+"时间登陆系统");

	}

}
