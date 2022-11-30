#ifndef __INIT_H__
#define __INIT_H__

#include "Clock.h"
#include <stdint.h>

// Color of LED
#define LED_RED 1
#define LED_GREEN (LED_RED << 1)
#define LED_BLUE (LED_RED << 2)

// Motor INITIALIZE
void pwn_init34(uint16_t period, uint16_t duty3, uint16_t duty4);
void motor_init(void);
void timer_A3_capture_init(void);


// Switch INITIALIZE
void switch_init(void);
void ir_sensor_init(void);
    
// LED UTILITY
void led_init(void);
void turn_on_led(int color);
void turn_off_led();

// INITIALZE all of things.
void init_all(void);

#endif // __INIT_H__