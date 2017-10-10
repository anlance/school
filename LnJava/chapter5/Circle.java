package chapter5;

public class Circle extends Geometry{
    double r;
    Circle(double r){
        this.r = r;
    }
    public double getArea(){
        return 3.14*this.r*this.r;
    }
}