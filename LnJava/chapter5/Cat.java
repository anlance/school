//package chapter5;
//Cat.java

class Cat extends Animal{
    Cat(){
        name = "猫";
    }
    Cat(String s){
        name = s;
    }
    public void cry(){
        System.out.println("喵、喵、喵、喵。。。");
    }
    public void climbUpTree(){
        System.out.println(name+"会爬树");
    }
}