package chapter5;

class Dog extends Animal{
    Dog(String s){
        name = s;
    }
    public void cry(){
        System.out.println("汪、汪、汪");
    }
    public void swimming(){
        System.out.println(name+"狗会游泳。。。。");
    }
}