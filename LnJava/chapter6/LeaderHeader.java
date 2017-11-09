//package chapter6;
//LeaderHerader.java

public class LeaderHeader{
    String battleContent;
    public void giveCommand(Commander com){
        com.batter(this.battleContent);
    }
    public void setBattleContent(String s){
        battleContent = s;
    }
}