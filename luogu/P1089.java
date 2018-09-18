import java.io.*;
import java.util.*;

public class P1089{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int judge = 0;
        int m_index = 0;
        int hand = 0;
        int mother = 0;
        for (int i=0;i<12;i++){
            int m = sc.nextInt();
            if (m<=300+hand){
                int temp = 300-m+hand;
                while(temp>=100){
                    temp-=100;
                    mother+=100;
                }
                hand = temp;
            }
            else{
                judge++;
                if(judge==1){
                    m_index = (i+1);
                }
            }
        }
        if(judge!=0){
            m_index = -m_index;
            System.out.print(m_index);
        }
        else{
            System.out.print((int)(mother*1.2+hand));
        }

    }
}