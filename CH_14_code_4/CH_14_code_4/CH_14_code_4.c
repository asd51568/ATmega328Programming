/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
int state = 0; // LED 점멸 상태
ISR(TIMER1_COMPA_vect)
{
	TCNT1 = 0; // 자동으로 0으로 변하지 않는다.
	state = !state; // LED 상태 반전
	if(state) PORTB = 0xFF; // LED 켜기
	else PORTB = 0x00; // LED 끄기
}
int main(void)
{
	DDRB = 0x20; // PB5 핀을 출력으로 설정
	PORTB = 0x00; // LED는 끈 상태에서 시작
	TCCR1B |= (1 << CS12) | (1 << CS10); // 분주비를 1024로 설정
	OCR1A = 0x2000; // 비교일치 기준값
	TIMSK1 |= (1 << OCIE1A); // 비교일치 인터럽트 허용
	sei(); // 전역적으로 인터럽트 허용
	while(1){ }
}