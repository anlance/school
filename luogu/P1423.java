import java.io.*;
import java.util.*;

public class P1423{
    public static void main(String[] args){
        int n = 1;
        Scanner sc = new Scanner(System.in);
        double need = sc.nextDouble();
        double start = 2.0;
        double temp = 2.0;
        while(temp<need){
            start *= 0.98;
            temp += start;
            n++;
        }
        System.out.print(n);
    }
}