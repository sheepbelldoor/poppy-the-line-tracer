#include "msp.h"
#include "Clock.h"
#include "motor.h"
#include "init.h"
#include <stdio.h>
#include <stdint.h>

#define SPEED 2000
#define LEFT_SPEED 2300
#define RIGHT_SPEED 2350
#define LOW_SPEED 1800
#define MAX_SPEED 4000
#define ROTATE_SPEED 4000

void line_turn_right() {
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


        if(ts1 > 200 && ts1<800) {
            move_forward(1, SPEED);
            rotate_right_degree(ROTATE_SPEED, 70);
            move_forward(1, SPEED);

            P5->OUT &= ~0x08;
            P9->OUT &= ~0x04;
            break;
        }
        else if (ts3 > 200 && ts3 < 800) {
            move(LOW_SPEED, SPEED);
        }
        else if(ts2 > 200 && ts2 < 800) {
            left_forward();
            right_backward();
            move(1000,1000);
        }
        else if (ts6 > 200 && ts6 < 800) {
            move(SPEED, LOW_SPEED);
        } 
        else if (ts7 > 200 && ts7 < 800) {
            left_backward();
           right_forward();
           move(1000,1000);
        } 
        else {
            move(SPEED, SPEED);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;

        Clock_Delay1ms(10);
    }
}

void move_until_white() {
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


        if(ts4<200 && ts5<200) {
            move(0,0);
            P5->OUT &= ~0x08;
            P9->OUT &= ~0x04;
            break;
        }
        else if (ts3 > 200 && ts3 < 800) {
            move(LOW_SPEED, SPEED);
        }
        else if (ts6 > 200 && ts6 < 800) {
            move(SPEED, LOW_SPEED);
        } 
        else {
            move(SPEED, SPEED);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;

        Clock_Delay1ms(10);
    }
}

void line_ignore() {

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
            move_forward(3, SPEED);
            P5->OUT &= ~0x08;
            P9->OUT &= ~0x04;
            break;
        }
        else if (ts3 > 200 && ts3 < 800) {
            move(LOW_SPEED, SPEED);
        }
        else if(ts2 > 200 && ts2 < 800) {
            left_forward();
            right_backward();
            move(1000,1000);
        }
        else if (ts6 > 200 && ts6 < 800) {
            move(SPEED, LOW_SPEED);
        } 
        else if (ts7 > 200 && ts7 < 800) {
            left_backward();
           right_forward();
           move(1000,1000);
        } 
        else {
            move(SPEED, SPEED);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;

        Clock_Delay1ms(10);
    }
}

void line_turn_left() {
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


        if(ts8 > 200 && ts8 <800) {
            move_forward(1,SPEED);
            rotate_left_degree(ROTATE_SPEED, 70);
            move_forward(1,SPEED);
            P5->OUT &= ~0x08;
            P9->OUT &= ~0x04;
            break;
        }
        else if (ts3 > 200 && ts3 < 800) {
            move(LOW_SPEED, SPEED);
        }
        else if(ts2 > 200 && ts2 < 800) {
            left_forward();
            right_backward();
            move(1000,1000);
        }
        else if (ts6 > 200 && ts6 < 800) {
            move(SPEED, LOW_SPEED);
        } 
        else if (ts7 > 200 && ts7 < 800) {
            left_backward();
           right_forward();
           move(1000,1000);
        } 
        else {
            move(SPEED, SPEED);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;

        Clock_Delay1ms(10);
    }
}

void main(void){
    init_all();

    int turn_count; // record number of turn count
    int lap_count = 3;

    move_forward(50, LEFT_SPEED, RIGHT_SPEED);

    while (lap_count < 2) {
        // section1 : Go straight until the first sensor is recognized & turn right 90 degrees after recognition
        line_turn_right();
        // section2 : Go straight until the first sensor is recognized & turn right 90 degrees after recognition
        line_turn_right();
        // section3 : Recognize but do not rotate
        line_ignore();
        // section4 : Go straight until the first sensor is recognized & turn right 90 degrees after recognition
        line_turn_right();
        // section5 : Go straight until the last sensor recognition & turn left 90 degrees after recognition
        line_turn_left();
        // section6 : Go straight until the first sensor is recognized & turn right 90 degrees after recognition
        line_turn_right();
        // section7 : Go straight until the last sensor recognition & turn left 90 degrees after recognition
        line_turn_left();
        // section8 : Recognize but do not rotate
        line_ignore();
        // section9 : Go straight until the last sensor recognition & turn left 90 degrees after recognition
        line_turn_left();
        // section10 : Go straight until the last sensor recognition & turn left 90 degrees after recognition
        line_turn_left();

        // section11 : line tracing section
        // 45degree rotate, todo

        // first shortcut
        line_turn_right();
        move_forward(5, SPEED);

        // second shortcut
        u_turn(44, SPEED);
        move_forward(5, SPEED);
        u_turn2(35, SPEED);

        // third shortcut
        line_turn_left();
        u_turn2(20, SPEED);
        u_turn(25,SPEED);

        line_turn_right();
        line_turn_right();

        // section12 : zigzag section
        // 45degree rotate todo
        move_forward(5,SPEED);
        rotate_right_degree(ROTATE_SPEED, 40);
        
        line_turn_left();
        line_turn_right();

        line_turn_left();
        line_turn_right();

        line_turn_left();
        line_turn_right();

        line_turn_left();

        rotate_left_degree(ROTATE_SPEED, 40);

        // section13 : Go straight until the last sensor recognition & turn left 90 degrees after recognition
        line_turn_left();
        // section14 : Go straight until the first sensor is recognized & turn right 90 degrees after recognition
        line_turn_right();

        // run to the end of the line
        // 340degree rotate
        // Linetracing
        move_until_white();
        rotate_right_degree(ROTATE_SPEED, 160);
        move_forward(5, SPEED);

        line_turn_left();
        line_turn_right();
        line_turn_right();
        line_turn_left();
        line_turn_left();
        line_turn_left();
        line_turn_right();

        move_until_white();
        rotate_right_degree(ROTATE_SPEED,100);
        move_until_white();
        rotate_left_degree(ROTATE_SPEED,100);

        line_turn_right();
        line_turn_right();
        line_turn_left();
        line_turn_right();

        // start lab recognition
        lap_count++;
    }
}
