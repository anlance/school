import java.util.*;

public class P1008{
    public static void main(String[] args){
        int a = 123;
        while(a<330){
            a++;
            int b = a*2;
            int c = a*3;
            int a1 = a/100;
            int a2 = a%10;
            int a3 = a%100/10;
            if(a1==a2||a2==a3||a1==a3||a2==0||a3==0){
                continue;
            }
            int b1 = b/100;
            int b2 = b%10;
            int b3 = b%100/10;
            if(b1==b2||b1==b3||b2==b3||b2==0||b3==0||a1==b1||a1==b2||a1==b3||a2==b1||a2==b2||a2==b3||a3==b1||a3==b2||a3==b3){
                continue;
            }
            int c1 = c/100;//百位
            int c2 = c%10;//个位
            int c3 = c%100/10;//十位
            if(c1==c2||c2==c3||c1==c3||c2==0||c3==0||a1==c1||a1==c2||a1==c3||a2==c1||a2==c2||a2==c3||a3==c1||a3==c2||a3==c3){
                continue;
            }
            if(b1==c1||b1==c2||b1==c3||b2==c1||b2==c2||b2==c3||b3==c1||b3==c2||b3==c3){
                continue;
            }
            System.out.println(a+" "+b+" "+c);
        }
    }
}
// 192 384 576
// 219 438 657
// 273 546 819
// 327 654 981