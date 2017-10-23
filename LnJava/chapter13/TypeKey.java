package chapter13;
//TypeKey.java

import chapter13.GiveLetterThread;
import chapter13.InputLetterThread;

public class TypeKey{
  public static void main(String []args){
    System.out.println("键盘练习（输入#结束程序）");
    System.out.println("输入显示的字母(回车)\n");
    Letter letter;
    letter = new Letter();
    GiveLetterThread giveChar;
    InputLetterThread typeChar;
    giveChar = new GiveLetterThread();
    giveChar.setLetter(letter);
    giveChar.setSleepLength(3200);
    typeChar = new InputLetterThread();
    typeChar.setLetter(letter);
    giveChar.start();
    typeChar.start();
  }
}