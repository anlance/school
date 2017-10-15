package chapter8;
//Check.java

class Goods{
    boolean isDanger;
    String name;
    Goods(String name){
        this.name = name;
    }
    public void setIsDanger(boolean boo){
        isDanger = boo;
    }
    public boolean isDanger(){
        return isDanger;
    }
    public String getName(){
        return this.name;
    }
}
class DangerException extends Exception{
    String message;
    public DangerException(){
        message = "危险品！";
    }
    public void toShow(){
        System.out.println(" "+message);
    }
}
class Machine{
    public void checkBag(Goods goods) throws DangerException{
        if(goods.isDanger()){
            DangerException dager = new DangerException();
            throw(dager);
        }
    }
}
public class Check{
    public static void main(String []args){
        Machine machine = new Machine();
        Goods apple = new Goods("苹果");
        apple.setIsDanger(false);
        Goods explosive = new Goods("炸药");
        explosive.setIsDanger(true);
        try{
            machine.checkBag(explosive);
            System.out.println(explosive.getName()+"检查通过");
        }
        catch(DangerException e){
            e.toShow();
            System.out.println(explosive.getName()+"被禁止！");
        }
        try{
            machine.checkBag(apple);
            System.out.println(apple.getName()+"检查通过");
        }
        catch(DangerException e){
            e.toShow();
            System.out.println(apple.getName()+"被禁止！");
        }
    }
}