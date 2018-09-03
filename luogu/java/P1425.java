import java.io.*;
import java.util.*;

public class P1425{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a[] = new int[4];
        int ansH = 0,ansM = 0;
        for (int i=0;i<4;i++){
            a[i] = sc.nextInt();
        }
        if(a[3]<a[1]){
            ansM = a[3]+60-a[1];
            ansH = a[2]-1-a[0];
        }else{
            ansM = a[3]-a[1];
            ansH = a[2]-a[0];
        }
        System.out.print(ansH+" "+ansM);
    }
}