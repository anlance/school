package club.anlan.lab1;

import android.support.annotation.NonNull;

public class UserRank implements Comparable <UserRank>{
    private int number;
    private String userName;
    private String usedTime;
    private String createdTime;

    public UserRank(){

    }

    public UserRank(int number, String userName, String usedTime, String createdTime){
        this.number = number;
        this.userName = userName;
        this.usedTime = usedTime;
        this.createdTime = createdTime;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getUsedTime() {
        return usedTime;
    }

    public void setUsedTime(String usedTime) {
        this.usedTime = usedTime;
    }

    public String getCreatedTime() {
        return createdTime;
    }

    public void setCreatedTime(String createdTime) {
        this.createdTime = createdTime;
    }


    @Override
    public int compareTo(@NonNull UserRank userRank) {
        int thisUsedTime = Integer.parseInt(this.getUsedTime().substring(0,this.getUsedTime().length()-1));
        int userUsedTime = Integer.parseInt(userRank.getUsedTime().substring(0,userRank.getUsedTime().length()-1));
        int thisNUmber = this.getNumber();
        int userNumber = userRank.getNumber();
        if(thisUsedTime > userUsedTime){
            if(thisNUmber < userNumber){
                this.setNumber(userNumber);
                userRank.setNumber(thisNUmber);
            }
            return 1;
        }
        else if(thisUsedTime < userUsedTime){
            if(thisNUmber > userNumber){
                this.setNumber(userNumber);
                userRank.setNumber(thisNUmber);
            }
            return -1;
        }
        else
            return 0;
    }
}
