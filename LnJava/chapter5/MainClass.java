//package chapter5;
//MainClass.java

public class MainClass{
    public static void main(String[] args){
        Dog dog = new Dog("uzi狂小狗");     
        //Dog dog1 = new Dog();     不可以
        Cat cat = new Cat("mata小野猫");
        Cat cat2 = new Cat();   //可以
        dog.showName();
        dog.cry();
        dog.swimming();
        cat.showName();
        cat.cry();
        cat.climbUpTree();
    }
}