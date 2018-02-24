//package 8.com;
//8不能作为包名

public class classDemo1{
    //公有方法
    public void mechod1(){
        System.out.println("这是一个公有的方法，任何类都可以访问");
    }

    //受保护的方法
    protected void mechod2(){
        System.out.println("这是一个受保护的方法，只有子类可以访问");
    }

    //私有的方法
    private void mechod3(){
        System.out.println("这是一个私有的方法，只有类本身可以访问");
    }

    public static void main(String[] args){
        classDemo1 d = new classDemo1();
        d.mechod1();
        d.mechod2();
        d.mechod3();
    }
}
