package chapter5;
//MainClass.java

public class MainClass{
    public static void main(String[] args){
        Dog dog = new Dog("uzi");
        Cat cat = new Cat("麻辣香锅…");
        dog.showName();
        dog.cry();
        dog.swimming();
        cat.showName();
        cat.cry();
        cat.climbUpTree();
    }
}