package chapter;
import java.util.Scanner;
public class Computer {
	public static void main(String args[]) {
		Scanner reader = new Scanner(System.in);
		double amount = 0;  //存放电量
		double price = 0;	//用户需要缴纳的电费
		System.out.println("输入电量:");
		amount = reader.nextDouble();
		if(amount < 90 &&amount >= 1) {
			price = amount * 0.6;
		}
		else if(amount <= 150 && amount >= 91) {
			price = (amount -90)* 1.1+90*0.6;
		}
		else if(amount > 150) {
			price = (amount-150) * 1.7+60*1.1+90*0.6;
		}
		else {
			System.out.println("输入电量："+amount+"不合理");
		}
		System.out.printf("电费：%5.2f",price);
	}
}
