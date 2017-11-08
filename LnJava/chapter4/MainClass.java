//package chapter4;
//MainClass.java

public class MainClass{
    public static void main(String[] args){
        Teacher zhang = new Teacher();
        Teacher wang = new Teacher();
        zhang.teacherType = 1;
        wang.teacherType = 2;
        School shiyanzhongxue = new School();
        shiyanzhongxue.setTeacher(zhang,wang);
        shiyanzhongxue.startMathLesson();
        shiyanzhongxue.startMusicLesson();
    }
}