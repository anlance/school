import java.io.*;
import java.util.*;

public class P1909{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int need =sc.nextInt();
        int min_money = 2100000000;
        for (int i=0;i<3;i++){
            int num = sc.nextInt();
            int money = sc.nextInt();
            int x = need%num;
            int temp = 0;
            if(x==0){
                temp = (need/num)*money;
            }
            else{
                temp = ((need/num)+1)*money;
            }
            if(temp<min_money){
                min_money=temp;
            }
        }
        System.out.print(min_money);
    }
}