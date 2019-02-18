package club.anlan.beans;

import club.anlan.dao.UserDao;
import service.UserService;

public class Service implements UserService {
    private String name;
    private Integer age;
    private UserDao userDao;


    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Integer getAge() {
        return age;
    }

    public void setAge(Integer age) {
        this.age = age;
    }

    public UserDao getUserDao() {
        return userDao;
    }

    public void setUserDao(UserDao userDao) {
        this.userDao = userDao;
    }

    @Override
    public void persist() {
        userDao.insert();
    }

    @Override
    public void printMsg() {
        System.out.println("姓名："+name);
        System.out.println("年龄："+age);
    }
}
