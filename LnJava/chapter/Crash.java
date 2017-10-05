package chapter;

public class Crash {
public static void main(String[] args) {
        
        int startPos = 0;
        int endPos = 0;
        char cStart = 'α';
        char cEnd = 'ω';
        startPos = cStart;
        endPos = cEnd;
        System.out.println("希腊字母\'α\'在unicode表中的顺序位置:" + startPos);
        System.out.println("希腊字母表:");
        for (int i = startPos; i <= endPos; i++) {
            char c = '\0';
            c = (char)i;
                    
            System.out.print(" " + c);
            
            if((i - startPos + 1) % 10 == 0)
                System.out.println(" ");
            
        }
        
    }

}
