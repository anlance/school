//package chapter9;
//Score.java
import java.util.*;
class ComputeeScore{
    double compute(String gradeForm){
        Scanner scanner = new Scanner(gradeForm);
        String regex = "[^0123456789]+";
        scanner.useDelimiter(regex);
        double sum = 0;
        while(scanner.hasNext()){
            try{
                double price = scanner.nextDouble();
                sum += price;
            }
            catch(InputMismatchException exp){
                String t = scanner.next();
            }
        }
        return sum;
    }
}

public class Score{
    public static void main(String []args){
        String []student = {
            "张三:数学 72,物理 67，英语 70",
            "李四:数学 92,物理 98，英语 88",
            "龙五:数学 68,物理 80，英语 77"                        
        };
        ComputeeScore jisuan = new ComputeeScore();
        for(String s:student){
            double totalScore = jisuan.compute(s);
            String name = s.substring(0,s.indexOf(":"));
            System.out.println(name+"总成绩"+totalScore);
        }
    }
}