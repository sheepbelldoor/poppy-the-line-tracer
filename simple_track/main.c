#include "msp.h"
#include "Clock.h"
#include <stdio.h>

#define LED_RED 1
#define LED_GREEN (LED_RED << 1)
#define LED_BLUE (LED_RED << 2)

uint16_t first_left;
uint16_t first_right;

uint16_t period_left;
uint16_t period_right;

void turn_on_led(int color) {
    P2->OUT &= ~0x07;
    P2->OUT |= color;
}

void turn_off_led() {
    P2->OUT &= ~0x07;
}

void switch_init() {
    P1->SEL0 &= ~0x12;
    P1->SEL1 &= ~0x12;

    P1->DIR &= ~0x12;
    P1->REN |= 0x12;
    P1->OUT |= 0x12;
}

void led_init() {
    P2->SEL0 &= ~0x07;
    P2->SEL1 &= ~0x07;

    P2->DIR |= 0x07;

    P2->OUT &= ~0x07;
}

void pwn_init34(uint16_t period, uint16_t duty3, uint16_t duty4) {
    //CCR0 period
    TIMER_A0->CCR[0] = period;

    //divide by 1
    TIMER_A0->EX0 = 0x0000;

    //toggle/reset
    TIMER_A0->CCTL[3] = 0x0040;
    TIMER_A0->CCR[3] = duty3;
    TIMER_A0->CCTL[4] = 0x0040;
    TIMER_A0->CCR[4] = duty4;

    TIMER_A0->CTL = 0x02F0;

    //set alternative
    P2->DIR |= 0xC0;
    P2->SEL0 |= 0xC0;
    P2->SEL1 &= ~0xC0;
}

void motor_init(void){
    P3->SEL0 &= ~0xC0;
    P3->SEL1 &= ~0xC0;
    P3->DIR |= 0xC0;
    P3->OUT &= ~0xC0;


    P5->SEL0 &= ~0x30;
    P5->SEL1 &= ~0x30;
    P5->DIR |= 0x30;
    P5->OUT &= ~0x30;



    P2->SEL0 &= ~0xC0;
    P2->SEL1 &= ~0xC0;
    P2->DIR |= 0xC0;
    P2->OUT &= ~0xC0;

    pwn_init34(7500,0,0);
}

void moveForward () {
    P5->OUT &= ~0x30;
    P2->OUT |= 0xC0;
    P3->OUT |= 0xC0;
    printf("hhh");
}

void stopPoppi() {
    P2->OUT &= ~0xC0;
}

void move(uint16_t leftDuty, uint16_t rightDuty) {
    P3->OUT |= 0xC0;
    TIMER_A0->CCR[3] = leftDuty;
    TIMER_A0->CCR[4] = rightDuty;
}

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

void timer_A3_capture_init() {
    P10->SEL0 |= 0x30;
    P10->SEL1 &= ~0x30;
    P10->DIR &= ~0x30;

    TIMER_A3->CTL &= ~0x0030;
    TIMER_A3->CTL = 0x0200;

    TIMER_A3->CCTL[0] = 0x4910;
    TIMER_A3->CCTL[1] = 0x4910;
    TIMER_A3->EX0 &= ~0x0007;

    NVIC->IP[3] = (NVIC->IP[3]&0x0000FFFF) | 0x404000000;
    NVIC->ISER[0] = 0x0000C000;
    TIMER_A3->CTL |= 0x0024;
}

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

uint32_t get_left_rpm() {
    return 2000000/period_left;
}

uint32_t get_right_rpm() {
    return 2000000/period_right;
}

uint32_t left_count;
uint32_t right_count;
void TA3_N_IRQHandler(void) {
    TIMER_A3->CCTL[1] &= ~0x0001;
    left_count++;
}
void TA3_0_IRQHandler(void) {
    TIMER_A3->CCTL[0] &= ~0x0001;
    right_count++;
}

void main(void){
    Clock_Init48MHz();
    led_init();
    // systick_init();
    motor_init ();
    timer_A3_capture_init();

    // IR sensor
    P5->SEL0 &= ~0x08;
    P5->SEL1 &= ~0x08;
    P5->DIR |= 0x08;
    P5->OUT &= ~0x08;

    P9->SEL0 &= ~0x04;
    P9->SEL1 &= ~0x04;
    P9->DIR |= 0x04;
    P9->OUT &= ~0x04;

    P7->SEL0 &= ~0xFF;
    P7->SEL1 &= ~0xFF;
    P7->DIR &= ~0xFF;

    // rotation 30 degree
//  while(1) {
//      left_backward();
//      right_forward();
//      move(700,700);
//      if(left_count>30 && right_count>30) {
//          move(0,0);
//          return;
//      } else {
//          printf("fff");
//      }
//  }


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
       printf("value %d %d %d %d %d %d %d %d \n", ts1, ts2, ts3, ts4, ts5, ts6, ts7 ,ts8);




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
