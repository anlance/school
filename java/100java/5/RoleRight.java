import java.util.*;

public class RoleRight{
    private static Hashtable rightList = new Hashtable<>();

    //初始化数据
    public void init(){
        String[] accRoleList = {"admin","satrap","manager","user","guest"};
        String[] rightCodeList = {"10001","10011","10021","20011","24011"};
        for(int i=0;i<accRoleList.length;i++){
            rightList.put(accRoleList[i],rightCodeList[i]);
        }
    }

    //获取角色权限代码
    public String getRight(String accRole){
        if(rightList.containsKey(accRole))
            return (String)rightList.get(accRole);
        else
            return null;
    }

    //添加角色和代码
    public void insert(String accRole, String rightCode){
        rightList.put(accRole, rightCode);
    }

    //删除角色权限
    public void delete(String accRole){
        if(rightList.containsKey(accRole))
            rightList.remove(accRole);
    }

    //修改角色权限代码
    public void update(String accRole, String rightCode){
        //this.delete(accRole);
        this.insert(accRole, rightCode);
    }

    //打印哈希表中角色和代码
    public void print(){
        Enumeration RLKey = rightList.keys();
        while(RLKey.hasMoreElements()){
            String accRole = RLKey.nextElement().toString();
            print(accRole+"="+this.getRight(accRole));
        }
    }

    //打印信息
    public void print(Object oPara){
        System.out.println(oPara);
    }

    public static void main(String[] args){
        RoleRight RR = new RoleRight();
        RR.init();
        RR.print();
        RR.print("___________________________");
        RR.insert("presider","10110");
        RR.print();
        RR.print("___________________________");
        RR.update("presider","10100");
        RR.print();
        RR.print("___________________________");
        RR.delete("presider");
        RR.print();
    } 
}