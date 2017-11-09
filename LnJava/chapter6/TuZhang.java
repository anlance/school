//package chapter6;
//TuangZhang.java

class TuZhang implements Commander{
    final int MaxSoldierNumber = 300;
    int soldierNumber = 1;
    String name;
    TuZhang(String s){
        this.name = s;
    }
    public void batter(String mess){
        System.out.println(this.name+"接收到作战指令："+mess);
        System.out.println(this.name+"指派"+this.soldierNumber+"人数参战");
        System.out.println(this.name+"保证完成任务！");
    }
    void setSoldierNumber(int m){
        if(m>MaxSoldierNumber){
            soldierNumber = MaxSoldierNumber;
        }else if(m<=MaxSoldierNumber && m>0){
            soldierNumber = m;
        }else{
            soldierNumber = 0;
        }
    }
}