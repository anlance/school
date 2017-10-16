package chapter9;
//FindMess.java

public class FindMess{
    public static void main(String []args){
    	String mess = "姓名:龙五  出生时间:1996.12.12。  个人网站:https://www.anlan.club。"+"身高:165 cm,体重:52 kg";
        int index = mess.indexOf(":");
        String name = mess.substring(index+1);
        if(name.startsWith("龙")){
            System.out.println("简历中的姓名姓\"龙\"");
        }
        index = mess.indexOf(":",index+1);
        String date =mess.substring(index+1,index+11);
        System.out.println(date);
        index = mess.indexOf(":",index+1);
        int heightPosition = mess.indexOf("身高");
        String personNet = mess.substring(index+1,heightPosition-1);
        System.out.println(personNet);
        index = mess.indexOf(":",heightPosition);
        int cmPosition = mess.indexOf("cm");
        String height = mess.substring(index+1,cmPosition);
        height = height.trim();
        int h = Integer.parseInt(height);
        if(h>=160){
            System.out.println("简历中的身高"+height+"大于或等于160cm");
        }
        else{
            System.out.println("简历中的身高"+height+"小于160cm");
        }
        index = mess.lastIndexOf(":");
        int kgPosition = mess.indexOf("kg");
        String weight = mess.substring(index+1,kgPosition);
        weight = weight.trim();
        int w = Integer.parseInt(weight);
        if(w>=55){
            System.out.println("简历中的体重"+weight+"大于或等于55kg");
        }
        else{
            System.out.println("简历中的体重"+weight+"小于55kg");
        }
    }
}