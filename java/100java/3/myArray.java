public class myArray{
    //初始化数组变量
    char[] cNum = {'1','2','3','4','5','6','7','8','9','0'};
    char[] cStr = {'a','b','c','d','e','f','g','h',
                  'i','j','k','l','m','n','o','p',
                  'q','r','s','t','u','v','w','x','y','z'};
   int[] iMonth = {31,28,31,30,31,30,31,31,30,31,30,31};
   String[] sMail = {"@","."};

   //校验电子邮件
   public boolean isMail(String sPara){
       for(int i=0;i<sMail.length;i++){
           if(sPara.indexOf(sMail[i])==-1)
                return false;
       }
       return true;
   }

   //判断是否数字
   public boolean isNumber(String sPara){
       int iPLength = sPara.length();
       for(int i=0;i<iPLength;i++){
           char cTemp = sPara.charAt(i);
           boolean bTemp = false;
           for(int j=0;j<cNum.length;j++){
               if(cTemp == cNum[j]){
                   bTemp = true;
                   break;
               }
           }
           if(!bTemp)
                return false;
       }
       return true;
   }

   //判断是否都是英文字母
   public boolean isString(String sPara){
       int iPLength = sPara.length();
       for(int i=0;i<iPLength;i++){
            char cTemp = sPara.charAt(i);
            boolean bTemp = false;
            for(int j=0;j<cStr.length;j++){
                if(cTemp==cStr[j]){
                    bTemp = true;
                break;
                }
            }
        if(!bTemp) return false; 
        }
    return true;
   }

   //判断是否闰年
   public boolean chickDay(int iPara){
       return iPara%100==0 && iPara%4==0;
   }

   //检查日期格式是否正确
   public int chickData(String sPara){
       boolean bTemp = false;
       if(sPara.length()!=10)
            return -2;
        String sYear = sPara.substring(0,4);
        if(!isNumber(sYear))
            return -2;
        String sMonth = sPara.substring(5,7);
        if(!isNumber(sMonth))
            return -2;
        String sDay = sPara.substring(8,10);
        if(!isNumber(sDay))
            return -2;
        int iYear = Integer.parseInt(sYear);
        int iMon = Integer.parseInt(sMonth);
        int iDay = Integer.parseInt(sDay);
        if(iMon>12)
            return -1;
        if(iMon==2&&chickDay(iYear))
            if(iDay>29)
                return 2;
            else{
                if(iDay>iMonth[iMon-1])
                    return -1;
            }
        return 0;
    }

    public static void main(String[] args){
        myArray mA = new myArray();
        // 校验邮件地址
        boolean bMail = mA.isMail("tom@163.com");
        System.out.println("1 bMail is"+bMail);
        bMail = mA.isMail("tom@163com");
        System.out.println("2 bMail is"+bMail);
        // 演示是否是数字
        boolean bIsNum = mA.isNumber("1234");
        System.out.println("1：bIsNum="+bIsNum);
        bIsNum = mA.isNumber("123r4");
        System.out.println("2：bIsNum="+bIsNum);
        // 演示是否是英文字符
        boolean bIsStr = mA.isString("wer");
        System.out.println("1：bIsStr="+bIsStr);
        bIsStr = mA.isString("wer3");
        System.out.println("2：bIsStr="+bIsStr);
        // 演示检查日期
        int iIsTime = mA.chickData("2003-12-98");
        System.out.println("1：iIsTime="+iIsTime);
        iIsTime = mA.chickData("2003-111-08");
        System.out.println("2：iIsTime="+iIsTime);
        iIsTime = mA.chickData("2003-10-08");
        System.out.println("3：iIsTime="+iIsTime);
        iIsTime = mA.chickData("2000-02-30");
        System.out.println("4：iIsTime="+iIsTime);
    }
}