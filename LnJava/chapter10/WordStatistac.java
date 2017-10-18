package chapter10;
//WordStatistic.java

import java.io.*;
import java.util.*;

public class WordStatistic{
    Vector<String> allWord,noSameWord;
    File file = new File("english.txt");
    Scanner sc = null;
    String regex;
    WordStatistic(){
        allWord = new Vector<String>();
        noSameWord = new Vector<String>();
        regex = "[\\s\\d\\p{Punct}]+";
        try{
            sc = new Scanner(file);
            sc.useDelimiter(regex);
        }
        catch(IOException exp){
            System.out.println(exp.toString());
        }
    }
    void setFileName(String name){
        file = new File(name);
        try{sc = new Scanner(file);
            sc.useDelimiter(regex);    
        }
        catch(IOException exp){
            System.out.println(exp.toString());
        }    
    }
    public void wordStatistic(){
        try{
            while(sc.hasNext()){
                String word = sc.next();
                allWord.add(word);
            }
        }
        catch(Exception e){}
    }
    public Vector<String> getNoSameWord(){
        return noSameWord;
    }
}