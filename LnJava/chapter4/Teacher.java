//package chapter4;
//Teacher.java

public class Teacher{
    int teacherType;
    public void speak(){
        if(teacherType==1){
            System.out.println("课程的内容是二次方程");
        }
        else
            System.out.println("课程的内容是学唱五线谱");
    }
}