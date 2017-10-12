package chapter6;
//LvZhang.java

class LvZhang implements Commander{
    final int MaxSoldierNumber = 1000;
    int soldierNumber = 1;
    String name;
    LvZhang(String s){
        this.name = s;
    }
    public void batter(String mess){
        System.out.println(this.name+"接收到作战指令："+mess);
        System.out.println(this.name+"指派"+this.soldierNumber+"人数参战");
        System.out.print(this.name+"保证完成任务！");
    }
    void setSoldierNmuber(int m){
        if(m>MaxSoldierNumber){
            soldierNumber = MaxSoldierNumber;
        }
        else if(m<MaxSoldierNumber && m>0){
            soldierNumber = m;
        }
    }

}