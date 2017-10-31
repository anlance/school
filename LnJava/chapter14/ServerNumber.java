//ServerNumber.java
//package chapter14;

import java.io.*;
import java.net.*;
import java.util.*;

import javax.net.ssl.ExtendedSSLSession;

class ServerThread extends Thread{
    Socket socket;
    DataInputStream in=null;
    DataOutputStream out=null;
    ServerThread(Socket t){
        socket = t;
        try{ out = new DataOutputStream(socket.getOutputStream());
            in = new DataInputStream(socket.getInputStream());
        }
        catch(IOException e){ }
    }
    public void run(){
        try{
            while(true){
                String str = in.readUTF();
                boolean boo = str.startsWith("Y")||str.startsWith("y");
                if(boo){
                    out.writeUTF("给你一个1-100之间的随机数，你猜才这个数是多少，猜不出来跟我信龙");
                    Random random = new Random();
                    int realNumber = random.nextInt(100)+1;
                    handleClientGuess(realNumber);
                    out.writeUTF("嘿嘿，输入Y继续，滚的话输入N！");
                }
                else{
                    return;
                }
            }
        }
        catch(Exception exp){ }
    }
    public void handleClientGuess(int realNumber){
        while(true){
            try{
                int clientGuess = in.readInt();
                System.out.println(clientGuess);
                if(clientGuess>realNumber)
                    out.writeUTF("猜大了，瓜皮");
                else if(clientGuess<realNumber)
                    out.writeUTF("猜小了，瓜瓜");
                else{
                    out.writeUTF("猜对了，乖乖");
                    break;
                }
            }
            catch (IOException e){
                System.out.println("客户（zhizhang）离开");
                return;
            }
        }
    }
}
public class ServerNumber{
    public static void main(String args[]){
        ServerSocket server = null;
        ServerThread thread;
        Socket you = null;
        while(true){
            try{ server = new ServerSocket(4331);
            }
            catch (IOException e){
                System.out.println("正在监听");
            }
            try {
                you = server.accept();
                System.out.println("客户的地址："+you.getInetAddress());
            }
            catch (IOException e){
                System.out.println("正在等待客户(zhizhang).....");
            }
            if(you != null){
                new ServerThread(you).start();
            }
        }
    }    
}