package chapter4;

public class School{
    Teacher mathTeacher,musicTeacher;
    void setTeacher(Teacher t1,Teacher t2){
        mathTeacher = t1;
        musicTeacher = t2;
    }
    void startMathLesson(){
        mathTeacher.speak();
    }
    void startMusicLesson(){
        musicTeacher.speak();
    }
}