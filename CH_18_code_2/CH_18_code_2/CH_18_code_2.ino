/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

char data = '0';
void setup(){
	Serial.begin(9600);
}
void loop(){
	Serial.println(data++);
	if(data > '9') data = '0';
	delay(1000);
}