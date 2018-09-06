import java.io.*;
import java.util.*;

public class P1422{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int c = sc.nextInt();
        double sa = 0.0;
        if(c<=150){
            sa += (double)(c*0.4463);
        }
        else if(c<=400){
            sa += (double)(150*0.4463+(c-150)*0.4663);
        }
        else{
            sa += (double)(150*0.4463+250*0.4663+(c-400)*0.5663);
        }
        sa = (double)Math.round(sa*10)/10.0;
        System.out.print(sa);
    }
} 