package chapter5;
//Animal.java

class Animal{
    protected String name;
    public void showName(){
        System.out.println(name);
    }
    public void cry(){
        System.out.println("不同动物的叫声是有区别的");
    }
}