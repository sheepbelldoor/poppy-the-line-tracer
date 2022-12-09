#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "msp.h"
#include "Clock.h"
#include <stdio.h>
#include <stdint.h>

int left_count_g;
int right_count_g;
// using in main
int left;
int right;

// ROTATE FUNCTION

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
void rotate_left_degree(int speed, int degree);
void rotate_right_degree(int speed, int degree);
void u_turn(int distance, uint16_t speed);
void u_turn2(int distance, uint16_t speed);

// MOVE FUNCTION
void move(uint16_t leftDuty, uint16_t rightDuty);
void left_forward();
void left_backward();
void right_forward();
void right_backward();
void move_forward(int distance, uint16_t speed); /* The unit of distance is centimeter */
void stop();

// etc...
// uint16_t first_left;
// uint16_t first_right;

// uint16_t period_left;
// uint16_t period_right;

// void TA3_0_IRQHandler(void);
// void TA3_N_IRQHandler(void);

#endif // __MOTOR_H__
