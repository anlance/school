package chapter6;
//CheckDogState.java

interface DogState{
    public void showState();
}
class SoftyState implements DogState{
    public void showState(){
        System.out.println("静静的趴在地上，闭着眼小憩....");
    }
}
class MeetEnemy implements DogState{
    public void showState(){
        System.out.println("竖起尾巴，朝敌人发出呜呜的低吼声，再狂吠...");
    }
}
class MeetFriendState implements DogState{
    public void cry(){
        System.out.println("摇晃尾巴，并欢快的跑来跑去...");
    }
}
class Dog{
    DogState state;
    public void cry(){
        state.showState();
    }
    public void setState(DogState s){
        this.state = s;
    }
}
public class CheckDogState{
    public static void main(String[] args){
        Dog taidi = new Dog();
        taidi.setState(new SoftyState());
        taidi.cry();
        taidi.setState(new MeetEnemy());
        taidi.cry();
        taidi.setState(new MeetFriendState());
        taidi.cry();
    }
}