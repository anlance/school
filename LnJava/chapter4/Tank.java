//package chapter4;
//Tank.java

public class Tank {
	double speed = 0.0;
	int bulletAmount = 0;
	void speedUp(int s) {
		speed += s;
	}
	void speedDown(int d) {
		if(speed>d)
			speed -= d;
		else
			speed = 0;
	}
	void setBulletAmount(int n) {
		bulletAmount = n;
	}
	int getBulletAmount() {
		return bulletAmount;
	}
	double getSpeed(){
		return speed;
	}
	void fire(){
		if(bulletAmount>0){
			bulletAmount -= 1;
			System.out.println("打出一发炮弹");
		}
		else
			System.out.println("没有炮弹了，无法开火");
	}
}
