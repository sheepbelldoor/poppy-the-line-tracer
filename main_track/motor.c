#include "motor.h"

// Function used to determine the turning radius.
void TA3_N_IRQHandler(void) {
    TIMER_A3->CCTL[1] &= ~0x0001;
    left_count_g++;
}
void TA3_0_IRQHandler(void) {
    TIMER_A3->CCTL[0] &= ~0x0001;
    right_count_g++;
}



void rotate_left_30_degree(int speed) {
    left_count_g = 0;
    right_count_g = 0;
    // rotation 30 degree
    while(1) {
        left_backward();
        right_forward();
        move(speed,speed);
        if(left_count_g>60 && right_count_g>60) {
            move(0,0);
            break;
        }
    }
}

void rotate_right_30_degree(int speed) {
    left_count_g = 0;
    right_count_g = 0;
    // rotation 30 degree
    while(1) {
        left_forward();
        right_backward();
        move(speed,speed);
        if(left_count_g>60 && right_count_g>60) {
            move(0,0);
            break;
        }
    }
}

void rotate_left_45_degree(int speed) {
    left_count_g = 0;
    right_count_g = 0;
    // rotation 45 degree
    while(1) {
        left_backward();
        right_forward();
        move(speed,speed);
        if(left_count_g>90 && right_count_g>90) {
            move(0,0);
            break;
        }
    }
}

void rotate_right_45_degree(int speed) {
    left_count_g = 0;
    right_count_g = 0;
    // rotation 30 degree
    while(1) {
        left_forward();
        right_backward();
        move(speed,speed);
        if(left_count_g>90 && right_count_g>90) {
            move(0,0);
            break;
        }
    }
}

void rotate_left_60_degree(int speed) {
    left_count_g = 0;
    right_count_g = 0;
    // rotate by 60 degree
    while(1) {
        left_backward();
        right_forward();
        move(speed,speed);
        if(left_count_g>120 && right_count_g>120) {
            move(0,0);
            break;
        }
    }
}

void rotate_right_60_degree(int speed) {
    left_count_g = 0;
    right_count_g = 0;
    // rotate by 60 degree
    while(1) {
        left_forward();
        right_backward();
        move(speed,speed);
        if(left_count_g>120 && right_count_g>120) {
            move(0,0);
            break;
        }
    }
}

void rotate_left_90_degree(int speed) {
    left_count_g = 0;
    right_count_g = 0;
    // rotate by 90 degree
    while(1) {
        left_backward();
        right_forward();
        move(speed,speed);
        if(left_count_g>180 && right_count_g>180) {
            move(0,0);
            break;
        }
    }
}

void rotate_right_90_degree(int speed) {
    left_count_g = 0;
    right_count_g = 0;
    // rotate by 90 degree
    while(1) {
        left_forward();
        right_backward();
        move(speed,speed);
        if(left_count_g>180 && right_count_g>180) {
            move(0,0);
            break;
        }
    }
}
void rotate_left_degree(int speed, int degree) {
    left_count_g = 0;
    right_count_g = 0;
    int count = degree * 2;
    // rotate by degree 
    while(1) {
        left_backward();
        right_forward();
        move(speed,speed);
        if(left_count_g>count && right_count_g>count) {
            move(0,0);
            break;
        }
    }
}
void rotate_right_degree(int speed, int degree) {
    left_count_g = 0;
    right_count_g = 0;
    int count = degree * 2;
    // rotate by degree 
    while(1) {
        left_forward();
        right_backward();
        move(speed,speed);
        if(left_count_g>count && right_count_g>count) {
            move(0,0);
            break;
        }
    }
}


// Move function parameter is move speed.
void move(uint16_t leftDuty, uint16_t rightDuty) {
    P3->OUT |= 0xC0;
    TIMER_A0->CCR[3] = leftDuty;
    TIMER_A0->CCR[4] = rightDuty;
}

// Set wheel's direction of rotation.
void left_forward() {
    P5->OUT &= ~0x10;
}
void left_backward() {
    P5->OUT |= 0x10;
}
void right_forward() {
    P5->OUT &= ~0x20;
}
void right_backward() {
    P5->OUT |= 0x20;
}
/* 16.3702 is 1cm */
void move_forward(int distance, uint16_t speed) {

    P3->OUT |= 0xC0;
    TIMER_A0->CCR[3] = speed;
    TIMER_A0->CCR[4] = speed;

    left_forward();
    right_forward();
    left_count_g = 0;
    right_count_g = 0;

    int dist = distance * 16.3702;

    while(1) {
        move(speed+80, speed);
        if(left_count_g>dist && right_count_g>dist) {
            move(0,0);
            break;
        }
    }
}

void u_turn(int distance, uint16_t speed) {

    P3->OUT |= 0xC0;
    TIMER_A0->CCR[3] = speed;
    TIMER_A0->CCR[4] = speed;

    left_forward();
    right_forward();
    left_count_g = 0;
    right_count_g = 0;

    int dist = distance * 16.3702;

    while(1) {
        move(speed, 0);
        if(right_count_g>dist) {
            move(0,0);
            break;
        }
    }
}

void u_turn2(int distance, uint16_t speed) {

    P3->OUT |= 0xC0;
    TIMER_A0->CCR[3] = speed;
    TIMER_A0->CCR[4] = speed;

    left_forward();
    right_forward();
    left_count_g = 0;
    right_count_g = 0;

    int dist = distance * 16.3702;

    while(1) {
        move(0, speed);
        if(left_count_g>dist) {
            move(0,0);
            break;
        }
    }
}

void rotate_left_until_black(int speed) {
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


        if((ts4 > 300 && ts4<1300) && (ts5 > 300 && ts5 < 1300)) {
            move(0, 0);
            break;
        }
        else {
            rotate_left_degree(speed, 1);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;

        Clock_Delay1ms(10);
    }
}
void rotate_right_until_black(int speed) {
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


        if((ts4 > 300 && ts4<1300) && (ts5 > 300 && ts5 < 1300)) {
            move(0, 0);
            break;
        }
        else {
            rotate_right_degree(speed, 1);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;

        Clock_Delay1ms(10);
    }
}

void stop() {
    P2->OUT &= ~0xC0;
}


// IRQ Handler
// uint16_t first_left;
// uint16_t first_right;

// uint16_t period_left;
// uint16_t period_right;

//void TA3_0_IRQHandler(void) {
//    TIMER_A3->CCTL[0] &= ~0x0001;
//    period_right = TIMER_A3->CCR[0] - first_right;
//    first_right = TIMER_A3->CCR[0];
//}
//
//void TA3_N_IRQHandler(void) {
//    TIMER_A3->CCTL[1] &= ~0x0001;
//    period_left = TIMER_A3->CCR[1] - first_left;
//    first_left = TIMER_A3->CCR[1];
//}
