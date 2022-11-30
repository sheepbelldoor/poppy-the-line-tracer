#include "motor.h"


uint32_t left_count = 0;
uint32_t right_count = 0;
// Function used to determine the turning radius.
void TA3_N_IRQHandler(void) {
    TIMER_A3->CCTL[1] &= ~0x0001;
    left_count++;
}
void TA3_0_IRQHandler(void) {
    TIMER_A3->CCTL[0] &= ~0x0001;
    right_count++;
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

// It makes poppy move forward or stop, but doesn't work...
void moveForward () {
    P5->OUT &= ~0x30;
    P2->OUT |= 0xC0;
    P3->OUT |= 0xC0;
}

void stop() {
    P2->OUT &= ~0xC0;
}


// UTILITY
// Check rpm of poppy.
uint32_t get_left_rpm() {
    return 2000000/period_left;
}

uint32_t get_right_rpm() {
    return 2000000/period_right;
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