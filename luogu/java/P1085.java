import java.io.*;
import java.util.*;

public class P1085 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] s = new int[7];
        int[] p = new int[7];
        int maxD = 8;
        int maxDIndex = 0;
        int k = 0;
        while (sc.hasNext()&&k<7) {
            s[k] = sc.nextInt();
            p[k] = sc.nextInt();
            k++;
            if(s[k-1]+p[k-1]>maxD){
                maxD = s[k-1]+p[k-1];
                maxDIndex = k;
            }
        }
        System.out.print(maxDIndex);
    }
}
