#include "msp.h"
#include "Clock.h"
#include "motor.h"
#include "init.h"
#include "section.h"
#include <stdio.h>
#include <stdint.h>

void main(void){
    init_all();

    int lap_count = 0;


    
    while (lap_count < 2) {
        // 구간1 : 첫번째 센서 인식할때까지 직진 & 인식 후 90도 우회전
        section1(2080, 2000, SPEED);
        // 구간2 : 첫번째 센서 인식할때까지 직진 & 인식 후 90도 우회전
        section2(2080, 2000, SPEED);
        // 구간3 : 인식해도 회전 안함
        section3(2080, 2000, SPEED);
        // 구간4 : 첫번째 센서 인식할때까지 직진 & 인식 후 90도 우회전
        section4(2080, 2000, SPEED);
        // 구간5 : 마지막 센서 인식할때까지 직진 & 인식 후 90도 좌회전
        section5(2080, 2000, SPEED);
        // 구간6 : 첫번째 센서 인식할때까지 직진 & 인식 후 90도 우회전
        section6(2080, 2000, SPEED);
        // 구간7 : 마지막 센서 인식할때까지 직진 & 인식 후 90도 좌회전
        section7(2080, 2000, SPEED);
        // 구간8 : 인식해도 회전 안함
        section8(2080, 2000, SPEED);
        // 구간9 : 마지막 센서 인식할때까지 직진 & 인식 후 90도 좌회전
        section9(2080, 2000, SPEED);
        // 구간10 : 마지막 센서 인식할때까지 직진 & 인식 후 90도 좌회전
        section10(2080, 2000, SPEED);
        // 구간11 : line tracing 부분
        section11(2080, 2000, SPEED);
        // 구간12 : 지그재그 부분
        section12(2080, 2000, SPEED);
        // 구간13 : 마지막 센서 인식할때까지 직진 & 인식 후 90도 좌회전
        section13(2080, 2000, SPEED);
        // 구간14 : 첫번째 센서 인식할때까지 직진 & 인식 후 90도 우회전
        section14(2080, 2000, SPEED);

        move_lap2(2080, 2000, SPEED, lap_count);
         
        // 시작 랩 인식
        lap_count++;
    }
    move(0,0);
    
}
