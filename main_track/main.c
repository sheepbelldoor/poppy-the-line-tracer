#include "msp.h"
#include "Clock.h"
#include "motor.h"
#include "init.h"
#include <stdio.h>
#include <stdint.h>


void section1() {
    while(1) {
        P5->OUT |= 0x08;
        P9->OUT |= 0x04;

        P7->DIR = 0xFF;
        P7->OUT = 0xFF;

        Clock_Delay1us(10);

        P7->DIR = 0x00;
        int timerTest;
        int ts1;
        int ts2;
        int ts3;
        int ts4;
        int ts5;
        int ts6;
        int ts7;
        int ts8;
        ts1 = 0;
        ts2 = 0;
        ts3 = 0;
        ts4 = 0;
        ts5 = 0;
        ts6 = 0;
        ts7 = 0;
        ts8 = 0;
        for(timerTest=0 ; timerTest<10000 ; timerTest++) {
            int s1;
            int s2;
            int s3;
            int s4;
            int s5;
            int s6;
            int s7;
            int s8;
            s1 = P7->IN & 0x01; // 1
            s2 = P7->IN & 0x02; // 2
            s3 = P7->IN & 0x04; // 3
            s4 = P7->IN & 0x08; // 4
            s5 = P7->IN & 0x10; // 5
            s6 = P7->IN & 0x20; // 6
            s7 = P7->IN & 0x40; // 7
            s8 = P7->IN & 0x80; // 8



            if(!ts1 && !s1) {
                ts1 = timerTest;
            }
            if(!ts2 && !s2) {
                ts2 = timerTest;
            }
            if(!ts3 && !s3) {
                ts3 = timerTest;
            }
            if(!ts4 && !s4) {
                ts4 = timerTest;
            }
            if(!ts5 && !s5) {
                ts5 = timerTest;
            }
            if(!ts6 && !s6) {
                ts6 = timerTest;
            }
            if(!ts7 && !s7) {
                ts7 = timerTest;
            }
            if(!ts8 && !s8) {
                ts8 = timerTest;
            }
        }

        right_forward();
        left_forward();


        if(ts1 > 200) {
            // 맨끝 센서 인식함 -> 멈춤, 90도 회전
            P5->OUT &= ~0x08;
            P9->OUT &= ~0x04;
            break;
        } else {
            move(1000,1000);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;

        Clock_Delay1ms(10);
    }
}

void section3() {

    while(1) {
        P5->OUT |= 0x08;
        P9->OUT |= 0x04;

        P7->DIR = 0xFF;
        P7->OUT = 0xFF;

        Clock_Delay1us(10);

        P7->DIR = 0x00;
        int timerTest;
        int ts1;
        int ts2;
        int ts3;
        int ts4;
        int ts5;
        int ts6;
        int ts7;
        int ts8;
        ts1 = 0;
        ts2 = 0;
        ts3 = 0;
        ts4 = 0;
        ts5 = 0;
        ts6 = 0;
        ts7 = 0;
        ts8 = 0;
        for(timerTest=0 ; timerTest<10000 ; timerTest++) {
            int s1;
            int s2;
            int s3;
            int s4;
            int s5;
            int s6;
            int s7;
            int s8;
            s1 = P7->IN & 0x01; // 1
            s2 = P7->IN & 0x02; // 2
            s3 = P7->IN & 0x04; // 3
            s4 = P7->IN & 0x08; // 4
            s5 = P7->IN & 0x10; // 5
            s6 = P7->IN & 0x20; // 6
            s7 = P7->IN & 0x40; // 7
            s8 = P7->IN & 0x80; // 8



            if(!ts1 && !s1) {
                ts1 = timerTest;
            }
            if(!ts2 && !s2) {
                ts2 = timerTest;
            }
            if(!ts3 && !s3) {
                ts3 = timerTest;
            }
            if(!ts4 && !s4) {
                ts4 = timerTest;
            }
            if(!ts5 && !s5) {
                ts5 = timerTest;
            }
            if(!ts6 && !s6) {
                ts6 = timerTest;
            }
            if(!ts7 && !s7) {
                ts7 = timerTest;
            }
            if(!ts8 && !s8) {
                ts8 = timerTest;
            }
        }

        right_forward();
        left_forward();


        if(ts1 > 200) {

            move(1000,1000);
            Clock_Delay1ms(100);
            P5->OUT &= ~0x08;
            P9->OUT &= ~0x04;
            break;
        } else {
            move(1000,1000);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;

        Clock_Delay1ms(10);
    }
}

void section4() {
    while(1) {
        P5->OUT |= 0x08;
        P9->OUT |= 0x04;

        P7->DIR = 0xFF;
        P7->OUT = 0xFF;

        Clock_Delay1us(10);

        P7->DIR = 0x00;
        int timerTest;
        int ts1;
        int ts2;
        int ts3;
        int ts4;
        int ts5;
        int ts6;
        int ts7;
        int ts8;
        ts1 = 0;
        ts2 = 0;
        ts3 = 0;
        ts4 = 0;
        ts5 = 0;
        ts6 = 0;
        ts7 = 0;
        ts8 = 0;
        for(timerTest=0 ; timerTest<10000 ; timerTest++) {
            int s1;
            int s2;
            int s3;
            int s4;
            int s5;
            int s6;
            int s7;
            int s8;
            s1 = P7->IN & 0x01; // 1
            s2 = P7->IN & 0x02; // 2
            s3 = P7->IN & 0x04; // 3
            s4 = P7->IN & 0x08; // 4
            s5 = P7->IN & 0x10; // 5
            s6 = P7->IN & 0x20; // 6
            s7 = P7->IN & 0x40; // 7
            s8 = P7->IN & 0x80; // 8



            if(!ts1 && !s1) {
                ts1 = timerTest;
            }
            if(!ts2 && !s2) {
                ts2 = timerTest;
            }
            if(!ts3 && !s3) {
                ts3 = timerTest;
            }
            if(!ts4 && !s4) {
                ts4 = timerTest;
            }
            if(!ts5 && !s5) {
                ts5 = timerTest;
            }
            if(!ts6 && !s6) {
                ts6 = timerTest;
            }
            if(!ts7 && !s7) {
                ts7 = timerTest;
            }
            if(!ts8 && !s8) {
                ts8 = timerTest;
            }
        }

        right_forward();
        left_forward();


        if(ts8 > 200) {
            // 맨끝 센서 인식함 -> 멈춤, 90도 회전
            P5->OUT &= ~0x08;
            P9->OUT &= ~0x04;
            break;
        } else {
            move(1000,1000);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;

        Clock_Delay1ms(10);
    }
}

void main(void){
    init_all();

    int turn_count; // 꺾은 횟수 기록
    int lap_count = 0;

    while (lap_count < 2) {
        // 구간1 : 첫번째 센서 인식할때까지 직진 & 인식 후 90도 우회전
        section1();
        // 구간2 : 첫번째 센서 인식할때까지 직진 & 인식 후 90도 우회전
        section1();
        // 구간3 : 인식해도 회전 안함
        section3();
        // 구간4 : 첫번째 센서 인식할때까지 직진 & 인식 후 90도 우회전
        section1();
        // 구간5 : 마지막 센서 인식할때까지 직진 & 인식 후 90도 좌회전
        section4();
        // 구간6 : 첫번째 센서 인식할때까지 직진 & 인식 후 90도 우회전
        section1();
        // 구간7 : 마지막 센서 인식할때까지 직진 & 인식 후 90도 좌회전
        section4();
        // 구간8 : 인식해도 회전 안함
        section3();
        // 구간9 : 마지막 센서 인식할때까지 직진 & 인식 후 90도 좌회전
        section4();
        // 구간10 : 마지막 센서 인식할때까지 직진 & 인식 후 90도 좌회전
        section4();

        // 구간11 : line tracing 부분
        // todo

        // 구간12 : 지그재그 부분
        // 45도 회전 todo
        section4();
        section1();

        section4();
        section1();

        section4();
        section1();

        section4();
        // 45도 회전 todo

        // 구간13 : 마지막 센서 인식할때까지 직진 & 인식 후 90도 좌회전
        section4();
        // 구간15 : 첫번째 센서 인식할때까지 직진 & 인식 후 90도 우회전
        section1();

        // 라인 끝까지 달리기
        // 340도 회전후 살짝 직진
        // 라인트레이싱


        //  시작 랩 인식
        lap_count++;
    }

    while(1) {
        P5->OUT |= 0x08;
        P9->OUT |= 0x04;

        P7->DIR = 0xFF;
        P7->OUT = 0xFF;

        Clock_Delay1us(10);

        P7->DIR = 0x00;
        int timerTest;
        int ts1;
        int ts2;
        int ts3;
        int ts4;
        int ts5;
        int ts6;
        int ts7;
        int ts8;
        ts1 = 0;
        ts2 = 0;
        ts3 = 0;
        ts4 = 0;
        ts5 = 0;
        ts6 = 0;
        ts7 = 0;
        ts8 = 0;
       for(timerTest=0 ; timerTest<10000 ; timerTest++) {
           int s1;
           int s2;
           int s3;
           int s4;
           int s5;
           int s6;
           int s7;
           int s8;
           s1 = P7->IN & 0x01; // 1
           s2 = P7->IN & 0x02; // 2
           s3 = P7->IN & 0x04; // 3
           s4 = P7->IN & 0x08; // 4
           s5 = P7->IN & 0x10; // 5
           s6 = P7->IN & 0x20; // 6
           s7 = P7->IN & 0x40; // 7
           s8 = P7->IN & 0x80; // 8



        if(!ts1 && !s1) {
            ts1 = timerTest;
        }
        if(!ts2 && !s2) {
            ts2 = timerTest;
        }
        if(!ts3 && !s3) {
            ts3 = timerTest;
        }
        if(!ts4 && !s4) {
            ts4 = timerTest;
        }
        if(!ts5 && !s5) {
            ts5 = timerTest;
       }
        if(!ts6 && !s6) {
            ts6 = timerTest;
        }
        if(!ts7 && !s7) {
           ts7 = timerTest;
        }
        if(!ts8 && !s8) {
            ts8 = timerTest;
        }
    }

        right_forward();
        left_forward();



        if(ts3>200 && ts6>200) {
           //finish line
           move(0,0);
        }
        else if (ts5>200 && ts4>200) {
            // forward
            left_forward();
            right_forward();
            move(1500,1500);
            printf("forward %d %d\n", ts5,ts4);
        } else if(ts3 > 200 || ts2 >200 || ts4>200) {
            // left
            left_forward();
            right_backward();
            move(1000,1000);
            printf("left %d\n", ts2);
        } else if(ts6 > 200 || ts7 > 200 || ts5>200) {
            // right
            left_backward();
            right_forward();
            move(1000,1000);
            printf("right %d\n", ts7);
        } else {
            move(0,0);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;

        Clock_Delay1ms(10);
    }
}
