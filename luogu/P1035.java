import java.io.*;
import java.util.*;

public class P1035{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        double temp=0.0;
        int k = sc.nextInt();
        int n = 0;
        while(temp<=(double)k){
            n++;
            temp += 1.0/n;
        }
        System.out.print(n);
    }
}