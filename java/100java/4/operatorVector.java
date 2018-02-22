import java.util.*;

public class operatorVector{

    //生成一个4*4的二维vector
    public Vector builcVector(){
        Vector vTemps = new Vector();
        for(int i=0;i<4;i++){
            Vector vTemp = new Vector();
            for(int j=0;j<4;j++){
                vTemp.addElement("Vector("+i+")("+j+")");
            }
            vTemps.addElement(vTemp);
        }
        return vTemps;
    }

    //插入数据
    public Vector insert(Vector vTemp, int iTemp, Object oTemp){
        if(iTemp>vTemp.size()){
            print("数组越界！");
            return null;
        }
        else{
            vTemp.insertElementAt(oTemp, iTemp);
        }
        return vTemp;
    }

    //移除数据
    public Vector delete(Vector vTemp, int iTemp){
        if(iTemp>vTemp.size()){
            print("数组越界！");
            return null;
        }
        else{
            vTemp.removeElementAt(iTemp);
        }
        return vTemp;
    }

    //modify data
    public Vector update(Vector vTemp, int iTemp, Object oTemp){
        if(iTemp>vTemp.size()){
            print("数组越界！");
            return null;
        }
        else{
            vTemp.setElementAt(oTemp, iTemp);
        }
        return vTemp;
    }

    //print data
    public void print(String sTemp, Object oTemp){
        System.out.println(sTemp+"数据：");
        this.print(oTemp);
    }

    public void print(Object oTemp){
        System.out.println(oTemp);
    }

    public void print(Vector vPara){
        for(int i=0;i<vPara.size();i++){
            System.out.println(vPara.elementAt(i));
        }
    }

    public static void main(String[] args){
        operatorVector ov = new operatorVector();
        Vector vTemp = ov.builcVector();
        ov.print("vTemp0",vTemp);
        Vector vResult = ov.insert(vTemp,2,"添加的数据");
        ov.print("vResult",vResult);
        Vector vResultup = ov.update(vResult, 2, "修改的数据");
        ov.print("vResultup",vResultup);
        Vector vResultnow = ov.delete(vResultup, 2);
        ov.print("vResultnow", vResultnow);
    }
}