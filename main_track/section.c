#include "section.h"

void section1(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
    straight_turn_right(left_speed, right_speed, SPEED);
}

void section2(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
    straight_turn_right(left_speed, right_speed, SPEED);
}

void section3(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
    straight_no_turn(left_speed, right_speed, SPEED);
}

void section4(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
    straight_turn_right(left_speed, right_speed, SPEED);
}

void section5(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
    straight_turn_left(left_speed, right_speed, SPEED);
}

void section6(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
    straight_no_turn(left_speed, right_speed, SPEED);
}

void section7(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
    straight_turn_left(left_speed, right_speed, SPEED);
}

void section8(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
    straight_no_turn(left_speed, right_speed, SPEED);
}

void section9(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
    straight_turn_left(left_speed, right_speed, SPEED);
}

void section10(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
    straight_turn_left(left_speed, right_speed, SPEED);
    rotate_left_degree(ROTATE_SPEED, 10);
}

void section11(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
    // First shortcut
    straight_turn_right(left_speed, right_speed, SPEED);
    straight_turn_right(left_speed, right_speed, SPEED);

    // Second shortcut
    straight_turn_left(left_speed, right_speed, SPEED);
    u_turn(5, SPEED);
    straight_turn_left_without_tracing(left_speed, right_speed, SPEED);

    // Sharp curve
    straight_turn_right_without_tracing(left_speed, right_speed, SPEED);
    move_forward(3, SPEED);
    u_turn2(7, SPEED);

    // Third shortcut
    straight_turn_left(left_speed, right_speed, SPEED);
    u_turn2(3, SPEED);
    straight_turn_left(left_speed, right_speed, SPEED);

    straight_turn_right(left_speed, right_speed, SPEED);
    straight_turn_right(left_speed, right_speed, SPEED);
}

void section12(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
    move_until_white(left_speed, right_speed, SPEED);
    rotate_right_degree(ROTATE_SPEED, 40);

    // Zig-zag
    straight_turn_left(left_speed, right_speed, SPEED);
    straight_turn_right(left_speed, right_speed, SPEED);
    straight_turn_left(left_speed, right_speed, SPEED);
    straight_turn_right(left_speed, right_speed, SPEED);
    straight_turn_left(left_speed, right_speed, SPEED);
    straight_turn_right(left_speed, right_speed, SPEED);

    straight_turn_left(left_speed, right_speed, speed);
    move_forward(5, speed);
    rotate_right_degree(ROTATE_SPEED, 40);
}

void section13(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
    straight_turn_left(left_speed, right_speed, SPEED);
}

void section14(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
    straight_turn_right(left_speed, right_speed, SPEED);
    
    move_until_white(left_speed, right_speed, SPEED);
    rotate_right_degree(ROTATE_SPEED, 140);

    straight_turn_left(left_speed, right_speed, SPEED);
    straight_turn_right(left_speed, right_speed, SPEED);
    straight_turn_right(left_speed, right_speed, SPEED);
    straight_turn_left(left_speed, right_speed, SPEED);
    straight_turn_left(left_speed, right_speed, SPEED);
    straight_turn_left(left_speed, right_speed, SPEED);
    straight_turn_right(left_speed, right_speed, SPEED);    

    move_until_white(left_speed, right_speed, SPEED);
    rotate_right_degree(ROTATE_SPEED, 100);
    move_until_white(left_speed, right_speed, SPEED);
    rotate_left_degree(ROTATE_SPEED, 100);

    straight_turn_right(left_speed, right_speed, SPEED);
    straight_turn_right(left_speed, right_speed, SPEED);
    straight_turn_left(left_speed, right_speed, SPEED);
    straight_turn_right(left_speed, right_speed, SPEED);
}

void straight_turn_right (uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
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
            move_forward(1, speed);
            rotate_right_degree(ROTATE_SPEED, 70);
            move_forward(1, speed);

            P5->OUT &= ~0x08;
            P9->OUT &= ~0x04;
            break;
        }
        else if(ts2 > 200 && ts2 < 800) {
            left_forward();
            right_backward();
            move(1000, 1000);
        }
        else if (ts7 > 200 && ts7 < 800) {
            left_backward();
            right_forward();
            move(1000, 1000);
        } 
        else if (ts3 > 200 && ts3 < 800) {
            move(LOW_SPEED, SPEED);
        }
        
        else if (ts6 > 200 && ts6 < 800) {
            move(SPEED, LOW_SPEED);
        } 
        
        else {
            move(left_speed, right_speed);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;

        Clock_Delay1ms(10);
    }
}

void straight_turn_right_without_tracing(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
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
            move_forward(1, speed);
            rotate_right_degree(ROTATE_SPEED, 70);
            move_forward(1, speed);

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
            move(left_speed, right_speed);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;

        Clock_Delay1ms(10);
    }
}

void move_until_white(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
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
            move(left_speed, right_speed);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;

        Clock_Delay1ms(10);
    }
}

void move_lap2(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
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


        if((ts4>200 && ts5>200) && (ts3>200 || ts6>200)) {
            move_forward(2, speed);
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
            move(left_speed, right_speed);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;

        Clock_Delay1ms(10);
    }
}

void straight_no_turn(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {

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


        if(ts1 > 200 || ts8>200) {

            move_forward(4, speed);
            P5->OUT &= ~0x08;
            P9->OUT &= ~0x04;
            break;
        }
        else if (ts7 > 200 && ts7 < 800) {
            left_backward();
            right_forward();
            move(left_speed, right_speed);
        } 
        else if(ts2 > 200 && ts2 < 800) {
            left_forward();
            right_backward();
            move(left_speed, right_speed);
        }
        else if (ts3 > 200 && ts3 < 800) {
            move(LOW_SPEED, SPEED);
        }
        
        else if (ts6 > 200 && ts6 < 800) {
            move(SPEED, LOW_SPEED);
        } 
        
        else {
            move(left_speed, left_speed);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;

        Clock_Delay1ms(10);
    }
}

void straight_turn_left(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
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
            rotate_left_degree(ROTATE_SPEED, 73);
            move_forward(1,SPEED);
            P5->OUT &= ~0x08;
            P9->OUT &= ~0x04;
            break;
        }
        else if (ts7 > 200 && ts7 < 800) {
            left_backward();
            right_forward();
            move(left_speed, right_speed);
        } 
         else if(ts2 > 200 && ts2 < 800) {
            left_forward();
            right_backward();
            move(left_speed, right_speed);
        }
        else if (ts3 > 200 && ts3 < 800) {
            move(LOW_SPEED, SPEED);
        }
        else if (ts6 > 200 && ts6 < 800) {
            move(SPEED, LOW_SPEED);
        } 
        
        else {
            move(left_speed, right_speed);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;

        Clock_Delay1ms(10);
    }
}

void straight_turn_left_without_tracing(uint16_t left_speed, uint16_t right_speed, uint16_t speed) {
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
        else if (ts6 > 200 && ts6 < 800) {
            move(SPEED, LOW_SPEED);
        } 
        
        else {
            move(left_speed, right_speed);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;

        Clock_Delay1ms(10);
    }
}
