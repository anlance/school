//package chapter5;
//Student.java

public class Student{
    public double Area(Geometry ...p){
        double sum = 0;
        for(int i=0;i<p.length;i++){
            sum += p[i].getArea();
        }
        return sum;
    }
}