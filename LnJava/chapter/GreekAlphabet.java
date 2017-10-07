package chapter;

import java.util.Scanner;
import java.util.Random;

public class GreekAlphabet {
	public static void main(String[] args) {
		Scanner reader =new Scanner(System.in);
		Random random = new Random();
		System.out.println("给你一个1-100的整数，请猜测这个数");
		int realNumber = random.nextInt(100)+1;
		int YourGuess = 0;
		YourGuess = reader.nextInt();
		while(YourGuess!=realNumber) {
			if(YourGuess<realNumber) {
				System.out.println("猜小了，请再输入你的猜测：");
				YourGuess = reader.nextInt();
			}
			else if(YourGuess>realNumber) {
				System.out.println("猜大了，请再输入你的猜测：");
				YourGuess = reader.nextInt();
			}
		}
		System.out.println("猜对了！");
	}
}
