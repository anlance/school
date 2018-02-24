import javax.lang.model.type.MirroredTypeException;

class  MyException extends Exception{
    public MyException(){}
    public MyException(String msg){
        super(msg);
    }

    public MyException(String msg, int x){
        super(msg);
        i = x;
    }

    public int val(){return i;}
    
    private int i;
}

public class DemoException{
    //使用 MyException 类中默认的构造器
    public static void a() throws MyException{
        System.out.println("throwing MyException from a()");
        throw new MyException();        
    }

    //使用 MyException 类中带信息的构造器
    public static void b() throws MyException{
        System.out.println("thorwing MyException from b()");
        throw new MyException("originated in b()");
    }

    //使用了 MyException 中有编码的构造器
    public static void c() throws MyException{
        System.out.println("throwing MyException from c()");
        throw new MyException("originated in c()", 47);
    }

    public static void main(String[] args){
        try{
            a();
        }
        catch(MyException e){
            e.toString();
        }
        try{
            b();
        }
        catch(MyException e){
            e.getMessage();
        }
        try{
            c();
        }
        catch(MyException e){
            e.printStackTrace();
            System.out.println("error code:"+e.val());
        }
    }
}