package chapter5;
//MainClass.java

public class MainClass2{
    public static void main(String[] args){
        Student gua = new Student();
        double theArea = gua.Area(new Rect(2,3),new Circle(5.2),new Circle(12));
        System.out.printf("2个圆形和一个矩形的面积之和：\n%10.3f"+theArea);
    }
}