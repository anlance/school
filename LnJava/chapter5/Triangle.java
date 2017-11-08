//package chapter5;
//Trangle.java
//假设直角
public class Triangle extends Geometry{
    double a,b;
    Triangle(double a,double b){
        this.a = a;
        this.b = b;
    }
    public double getArea(){
        return a*b*0.5;
    }
}