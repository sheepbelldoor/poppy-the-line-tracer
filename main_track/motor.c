#include "motor.h"



// Function used to determine the turning radius.
void TA3_N_IRQHandler(void) {
    TIMER_A3->CCTL[1] &= ~0x0001;
    left_count_g++;
    left_taco++;
}
void TA3_0_IRQHandler(void) {
    TIMER_A3->CCTL[0] &= ~0x0001;
    right_count_g++;
    right_taco++;
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
    // rotation 30 degree
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
    // rotation 30 degree
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
    // rotation 30 degree
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
    // rotation 30 degree
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
    left_forward();
    right_forward();
    left_count_g = 0;
    right_count_g = 0;

    int dist = distance * 16.3702;

    while(1) {
        move(speed, speed);
        if(left_count_g>dist && right_count_g>dist) {
            move(0,0);
            break;
        }
    }
}

void stop() {
    P2->OUT &= ~0xC0;
}

void move_distance(int distance, uint16_t left_speed, uint16_t right_speed) {
    left_forward();
    right_forward();
    left_count_g = 0;
    right_count_g = 0;

    int dist = distance * 16.3702;

    while(1) {
        move(left_speed, right_speed);
        if(left_count_g>dist && right_count_g>dist) {
            move(0,0);
            break;
        }
    }
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
