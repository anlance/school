package chapter8;
//MianClass.java

class MobileShop{
    InnerPurchaseMony purchaseMony1,purchaseMony2;
    MobileShop(){
        purchaseMony1 = new InnerPurchaseMony(20000);
        purchaseMony2 = new InnerPurchaseMony(10000);
    }
    void setMobileAmount(int m){
        mobileAmount = m;
    }
    int getMobileAmount(){
        return mobileAmount;
    }
    private int mobileAmount;
    class InnerPurchaseMony{
        int moneyValue;
        InnerPurchaseMony(int m){
            this.moneyValue = m;
        }
        void buyMobile(){
            if(moneyValue>=20000){
                mobileAmount = mobileAmount - 6;
                System.out.println("用价值"+moneyValue+"的内部购物券购买了6部手机");
            }
           else if(moneyValue<20000&&moneyValue>=10000){
               mobileAmount = mobileAmount - 3;
               System.out.println("用价值"+moneyValue+"的内部购物券购买了3部手机");
           }
        }
    }
}

public class MainClass{
    public static void main(String []args){
        MobileShop shop = new MobileShop();
        shop.setMobileAmount(30);
        System.out.println("手机专卖店目前有"+shop.getMobileAmount()+"部手机");
        shop.purchaseMony1.buyMobile();
        shop.purchaseMony2.buyMobile();
        System.out.println("手机专卖店目前有"+shop.getMobileAmount()+"部手机");        
    }
}