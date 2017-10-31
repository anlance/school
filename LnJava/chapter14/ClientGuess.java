//ClientGuess.java
//package chapter14;

import java.io.*;
import java.net.*;
import java.util.*;

class ReadNumber implements Runnable{
    Scanner scanner = new Scanner(System.in);
    DataInputStream in;
    DataOutputStream out;
    public void setDataOutputStream(DataOutputStream out){
        this.out = out;
    }
    public void setDataInputStream(DataInputStream in){
        this.in = in;
    }
    public void run(){
        try{
            out.writeUTF("Y");
            while(true){
                String str = in.readUTF();
                System.out.println(str);
                if(! str.startsWith("嘿嘿")){
                    if(str.startsWith("猜对了"))
                        continue;
                    System.out.print("wocao!我输入猜测：");
                    int myGuess = scanner.nextInt();
                    String enter = scanner.nextLine();
                    out.writeInt(myGuess);
                }
                else{
                    System.out.print("好的，我输入Y或者N:");
                    String myAnswer =scanner.nextLine();
                    out.writeUTF(myAnswer);
                }
            }
        }
        catch (Exception e){
            System.out.println("与服务器已断开"+e);
            return;
        }
    }
}

public class ClientGuess{
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        Socket mysocket = null; 
        DataInputStream inData = null;
        DataOutputStream outData = null;
        Thread thread;
        ReadNumber readNumber = null;
        try{
            mysocket = new Socket();
            readNumber = new ReadNumber();
            thread = new Thread(readNumber);
            System.out.print("输入服务器的IP:");
            String IP = scanner.nextLine();
            System.out.print("输入端口号：");
            int port = scanner.nextInt();
            if(mysocket.isConnected()){ }
            else{
                InetAddress address = InetAddress.getByName(IP);
                InetSocketAddress socketAddress = new InetSocketAddress(address, port);
                mysocket.connect(socketAddress);
                InputStream in = mysocket.getInputStream();
                OutputStream out = mysocket.getOutputStream();
                inData = new DataInputStream(in);
                outData = new DataOutputStream(out);
                readNumber.setDataInputStream(inData);
                readNumber.setDataOutputStream(outData);
                thread.start();
            }
        }
        catch(Exception e){
            System.out.println("服务器已断开"+e);
        }
    }
}