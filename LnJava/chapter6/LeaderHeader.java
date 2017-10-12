package chapter6;
//LeaderHerader.java

public class LeaderHeader implements Commander{
    String battleContent;
    public void giveCommand(Commader com){
        com.battle(battleContent);
    }
    public void setBattleContent(String s){
        battleContent = s;
    }
}