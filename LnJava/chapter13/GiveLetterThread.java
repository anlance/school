package chapter13;
//GiveLettrThread.java

public class GiveLetterThread extends Thread{
  Letter letter;
  char startChar = 'a', endChar = 'c';
  int sleepLength = 5000;
  public void setLetter(Letter letter){
    this.letter = letter;
  }
  public void setSleepLength(int n){
    sleepLength = n;
  }
  public void run(){
    char c = startChar;
    while(true){
      letter.setChar(c);
      System.out.printlf("显示的字符：%c\n",letter.getChar());
      try{
        Thread.sleep(sleepLength);
      }
      catch(InterruptedException e){}
      c = (char)(c+1);
      if(c>endChar)
      c = startChar;
    }
  }
}