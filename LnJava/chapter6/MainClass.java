//package chapter6;
//MianClass.java

public class MainClass{
    public static void main(String[] args){
        LeaderHeader leader = new LeaderHeader();
        ShiZhang oneShi = new ShiZhang("第一师");
        oneShi.setSoldierNumber(996);
        leader.setBattleContent("进攻北城");
        leader.giveCommand(oneShi);
        LvZhang oneLv = new LvZhang("第一旅");
        oneLv.setSoldierNumber(567);
        leader.setBattleContent("在2号公路阻击敌人");
        leader.giveCommand(oneLv);
        TuZhang onetuan = new TuZhang("炮兵团");
        onetuan.setSoldierNumber(250);
        leader.setBattleContent("在6号公路开炮");
        leader.giveCommand(onetuan);
    }
}