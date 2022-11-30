#ifndef __MOTOR_H__
#define __MOTOR_H__

#include <stdint.h>


// ROTATE FUNCTION
uint32_t left_count_g = 0;
uint32_t right_count_g = 0;
void TA3_N_IRQHandler(void);
void TA3_0_IRQHandler(void);
void rotate_left_30_degree(int speed);
void rotate_right_30_degree(int speed);
void rotate_left_45_degree(int speed);
void rotate_right_45_degree(int speed);
void rotate_left_60_degree(int speed);
void rotate_right_60_degree(int speed);
void rotate_left_90_degree(int speed);
void rotate_right_90_degree(int speed);


// MOVE FUNCTION
void move(uint16_t leftDuty, uint16_t rightDuty);
void left_forward();
void left_backward();
void right_forward();
void right_backward();

// UITLITY
void moveForward ();
void stop();

uint32_t get_left_rpm();
uint32_t get_right_rpm();

// etc...
// uint16_t first_left;
// uint16_t first_right;

// uint16_t period_left;
// uint16_t period_right;

// void TA3_0_IRQHandler(void);
// void TA3_N_IRQHandler(void);

#endif // __MOTOR_H__