#ifndef BOARD_STM32V1F4
#define BOARD_STM32V1F4

#include "laserlab_MP32V1F4.h"
#include "gpio_hal.h"
#include "adc.h"
#include "timer.h"
#include "wirish_types.h"

void boardInit(void) {

    /* DA ATTIVARE SOLO CON PPMSUM ACTIVE
     * le uscite che usano i servi dalla 10-13 sono a 60 hz
     * anzich� a 550 cos� i servi non bruciano.
     */

    //unsigned short Reload;
    //unsigned short uFreq = MOTOR_PWM_FREQ;
    //if (uFreq > 550) uFreq = 550;
    //if (uFreq < 50) uFreq = 50;
    //Reload = (unsigned short)(0xFFFF * 50 / uFreq);
    // SI USA CON HEXA
    //timer_pause(TIMER4);
    //timer_set_prescaler(TIMER4, 21);    // 60 Hz nel caso di conf quad
    //timer_set_prescaler(TIMER4, 1);     // 550 Hz nel caso di conf hexa
    //timer_set_count(TIMER4, 0);
    //timer_set_reload(TIMER4, Reload);
    //timer_resume(TIMER4);

//    afio_remap(AFIO_REMAP_USART2);
//    afio_remap(AFIO_REMAP_USART3);
//    afio_remap(AFIO_REMAP_TIM3_PARTIAL);

}

extern const stm32_pin_info PIN_MAP[BOARD_NR_GPIO_PINS] = {

    /* Top header */

    {_GPIOB,   NULL, NULL, 10, 0, ADCx}, /* D0/PB10  0*/
    {_GPIOB,   NULL, NULL,  2, 0, ADCx}, /* D1/PB2   1*/
    {_GPIOB,   NULL, NULL, 12, 0, ADCx}, /* D2/PB12  2*/
    {_GPIOB,   NULL, NULL, 13, 0, ADCx}, /* D3/PB13  3*/
    {_GPIOB,   NULL, NULL, 14, 0, ADCx}, /* D4/PB14  4*/
    {_GPIOB,   NULL, NULL, 15, 0, ADCx}, /* D5/PB15  5*/
    {_GPIOC,   NULL, _ADC1,  0, 0,   10}, /* D6/PC0  6*/
    {_GPIOC,   NULL, _ADC1,  1, 0,   11}, /* D7/PC1  7*/
    {_GPIOC,   NULL, _ADC1,  2, 0,   12}, /* D8/PC2  8*/
    {_GPIOC,   NULL, _ADC1,  3, 0,   13}, /* D9/PC3  9*/
    {_GPIOC,   NULL, _ADC1,  4, 0,   14}, /* D10/PC4 10*/
    {_GPIOC,   NULL, _ADC1,  5, 0,   15}, /* D11/PC5 1*/
    {_GPIOC, TIMER8, NULL,  6, 1, ADCx}, /* D12/PC6  2 CH5_IN*/
    {_GPIOC, TIMER8, NULL,  7, 2, ADCx}, /* D13/PC7  3 CH6_IN*/
    {_GPIOC, TIMER8, NULL,  8, 3, ADCx}, /* D14/PC8  4 CH7_IN*/
    {_GPIOC, TIMER8, NULL,  9, 4, ADCx}, /* D15/PC9  5 CH8_IN*/
    {_GPIOC,   NULL, NULL, 10, 0, ADCx}, /* D16/PC10 6*/
    {_GPIOC,   NULL, NULL, 11, 0, ADCx}, /* D17/PC11 7*/
    {_GPIOC,   NULL, NULL, 12, 0, ADCx}, /* D18/PC12 8*/
    {_GPIOC,   NULL, NULL, 13, 0, ADCx}, /* D19/PC13 9*/
    {_GPIOC,   NULL, NULL, 14, 0, ADCx}, /* D20/PC14 20*/
    {_GPIOC,   NULL, NULL, 15, 0, ADCx}, /* D21/PC15 1*/
    {_GPIOA, TIMER1, NULL,  8, 1, ADCx}, /* D22/PA8  2*/
    {_GPIOA, TIMER1, NULL,  9, 2, ADCx}, /* D23/PA9  3*/
    {_GPIOA, TIMER1, NULL, 10, 3, ADCx}, /* D24/PA10 4*/
    {_GPIOB, TIMER4, NULL,  9, 4, ADCx}, /* D25/PB9  5 CH_8_OUT I2C2_SDA */

    /* Bottom header */
    /* Note: D{48, 49, 50, 51} are also TIMER2_CH{1, 2, 3, 4}, respectively. */
    /* TODO remap timer 2 in boardInit(); make the appropriate changes here */

    {_GPIOD,   NULL, NULL,  2, 0, ADCx}, /* D26/PD2  6*/
    {_GPIOD,   NULL, NULL,  3, 0, ADCx}, /* D27/PD3  7*/
    {_GPIOD,   NULL, NULL,  6, 0, ADCx}, /* D28/PD6  8*/
    {_GPIOG,   NULL, NULL, 11, 0, ADCx}, /* D29/PG11 9*/
    {_GPIOG,   NULL, NULL, 12, 0, ADCx}, /* D30/PG12 30*/
    {_GPIOG,   NULL, NULL, 13, 0, ADCx}, /* D31/PG13 1*/
    {_GPIOG,   NULL, NULL, 14, 0, ADCx}, /* D32/PG14 2*/
    {_GPIOG,   NULL, NULL,  8, 0, ADCx}, /* D33/PG8  3*/
    {_GPIOG,   NULL, NULL,  7, 0, ADCx}, /* D34/PG7  4*/
    {_GPIOG,   NULL, NULL,  6, 0, ADCx}, /* D35/PG6  5*/
    {_GPIOB, TIMER3, NULL,  5, 2, ADCx}, /* D36/PB5  6*/
    {_GPIOB, TIMER4, NULL,  6, 1, ADCx}, /* D37/PB6  7*/
    {_GPIOB, TIMER4, NULL,  7, 2, ADCx}, /* D38/PB7  8*/
    {_GPIOF,   NULL, _ADC3,  6, 0,    4}, /* D39/PF6 9*/
    {_GPIOF,   NULL, _ADC3,  7, 0,    5}, /* D40/PF7 40*/
    {_GPIOF,   NULL, _ADC3,  8, 0,    6}, /* D41/PF8 1*/
    {_GPIOF,   NULL, _ADC3,  9, 0,    7}, /* D42/PF9 2*/
    {_GPIOF,   NULL, _ADC3, 10, 0,    8}, /* D43/PF10 3*/
    {_GPIOF,   NULL, NULL, 11, 0, ADCx}, /* D44/PF11 4*/
    {_GPIOB, TIMER3, _ADC1,  1, 4,    9}, /* D45/PB1 5*/
    {_GPIOB, TIMER3, _ADC1,  0, 3,    8}, /* D46/PB0 6*/
    {_GPIOA, TIMER2, _ADC1,  0, 1,    0}, /* D47/PA0 7*/
    {_GPIOA, TIMER2, _ADC1,  1, 2,    1}, /* D48/PA1 8*/
    {_GPIOA, TIMER2, _ADC1,  2, 3,    2}, /* D49/PA2 9*/
    {_GPIOA, TIMER2, _ADC1,  3, 4,    3}, /* D50/PA3 50*/
    {_GPIOA,   NULL, _ADC1,  4, 0,    4}, /* D51/PA4 1*/
    {_GPIOA,   NULL, _ADC1,  5, 0,    5}, /* D52/PA5 2*/
    {_GPIOA, TIMER3, _ADC1,  6, 1,    6}, /* D53/PA6 3*/
    {_GPIOA, TIMER3, _ADC1,  7, 2,    7}, /* D54/PA7 4*/

    /* FSMC (triple) header */

    {_GPIOF,   NULL, NULL,  0, 0, ADCx}, /* D55/PF0  5*/
    {_GPIOD,   NULL, NULL, 11, 0, ADCx}, /* D56/PD11 6*/
    {_GPIOD, TIMER4, NULL, 14, 3, ADCx}, /* D57/PD14 7*/
    {_GPIOF,   NULL, NULL,  1, 0, ADCx}, /* D58/PF1  8*/
    {_GPIOD, TIMER4, NULL, 12, 1, ADCx}, /* D59/PD12 9*/
    {_GPIOD, TIMER4, NULL, 15, 4, ADCx}, /* D60/PD15 60*/
    {_GPIOF,   NULL, NULL,  2, 0, ADCx}, /* D61/PF2  1*/
    {_GPIOD, TIMER4, NULL, 13, 2, ADCx}, /* D62/PD13 2*/
    {_GPIOD,   NULL, NULL,  0, 0, ADCx}, /* D63/PD0  3*/
    {_GPIOF,   NULL, NULL,  3, 0, ADCx}, /* D64/PF3  4*/
    {_GPIOE,   NULL, NULL,  3, 0, ADCx}, /* D65/PE3  5*/
    {_GPIOD,   NULL, NULL,  1, 0, ADCx}, /* D66/PD1  6*/
    {_GPIOF,   NULL, NULL,  4, 0, ADCx}, /* D67/PF4  7*/
    {_GPIOE,   NULL, NULL,  4, 0, ADCx}, /* D68/PE4  8*/
    {_GPIOE,   NULL, NULL,  7, 0, ADCx}, /* D69/PE7  9*/
    {_GPIOF,   NULL, NULL,  5, 0, ADCx}, /* D70/PF5  70*/
    {_GPIOE,   NULL, NULL,  5, 0, ADCx}, /* D71/PE5  1*/
    {_GPIOE,   NULL, NULL,  8, 0, ADCx}, /* D72/PE8  2*/
    {_GPIOF,   NULL, NULL, 12, 0, ADCx}, /* D73/PF12 3*/
    {_GPIOE,   NULL, NULL,  6, 0, ADCx}, /* D74/PE6  4*/
    {_GPIOE,   TIMER1, NULL,  9, 1, ADCx}, /* D75/PE9  CH1_IN - PPMSUM*/
    {_GPIOF,   NULL, NULL, 13, 0, ADCx}, /* D76/PF13 6*/
    {_GPIOE,   NULL, NULL, 10, 0, ADCx}, /* D77/PE10 7*/
    {_GPIOF,   NULL, NULL, 14, 0, ADCx}, /* D78/PF14 8*/
    {_GPIOG,   NULL, NULL,  9, 0, ADCx}, /* D79/PG9  9*/
    {_GPIOE,   TIMER1, NULL, 11, 2, ADCx}, /* D80/PE11 CH2_IN*/
    {_GPIOF,   NULL, NULL, 15, 0, ADCx}, /* D81/PF15 1*/
    {_GPIOG,   NULL, NULL, 10, 0, ADCx}, /* D82/PG10 2*/
    {_GPIOE,   NULL, NULL, 12, 0, ADCx}, /* D83/PE12 3*/
    {_GPIOG,   NULL, NULL,  0, 0, ADCx}, /* D84/PG0  4*/
    {_GPIOD,   NULL, NULL,  5, 0, ADCx}, /* D85/PD5  5*/
    {_GPIOE,   TIMER1, NULL, 13, 3, ADCx}, /* D86/PE13 CH3_IN*/
    {_GPIOG,   NULL, NULL,  1, 0, ADCx}, /* D87/PG1  7*/
    {_GPIOD,   NULL, NULL,  4, 0, ADCx}, /* D88/PD4  8*/
    {_GPIOE,   TIMER1, NULL, 14, 4, ADCx}, /* D89/PE14 CH4_IN*/
    {_GPIOG,   NULL, NULL,  2, 0, ADCx}, /* D90/PG2  90*/
    {_GPIOE,   NULL, NULL,  1, 0, ADCx}, /* D91/PE1  1*/
    {_GPIOE,   NULL, NULL, 15, 0, ADCx}, /* D92/PE15 2*/
    {_GPIOG,   NULL, NULL,  3, 0, ADCx}, /* D93/PG3  3*/
    {_GPIOE,   NULL, NULL,  0, 0, ADCx}, /* D94/PE0  4*/
    {_GPIOD,   NULL, NULL,  8, 0, ADCx}, /* D95/PD8  5*/
    {_GPIOG,   NULL, NULL,  4, 0, ADCx}, /* D96/PG4  6*/
    {_GPIOD,   NULL, NULL,  9, 0, ADCx}, /* D97/PD9  7*/
    {_GPIOG,   NULL, NULL,  5, 0, ADCx}, /* D98/PG5  8*/
    {_GPIOD,   NULL, NULL, 10, 0, ADCx}, /* D99/PD10 9*/
    {_GPIOB,   NULL, NULL, 11, 0, ADCx}, /* D100/PB11 100*/
    {_GPIOB, TIMER4, NULL,  8, 3, ADCx}, /* D101/PB8 1 CH7_OUT I2C2_SCL*/
    {_GPIOE,   NULL, NULL,  2, 0, ADCx}  /* D102/PE2 */
};

extern const uint8_t boardPWMPins[BOARD_NR_PWM_PINS] __FLASH__ = {
    13, 14, 15, 16, 23, 24, 25, 26, 38, 39, 46, 47, 48, 49, 50, 51, 54, 55
};

extern const uint8_t boardADCPins[BOARD_NR_ADC_PINS] __FLASH__ = {
    7, 8, 9, 10, 11, 12, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53,
    54, 55
};

extern const uint8_t boardUsedPins[BOARD_NR_USED_PINS] __FLASH__ = {
    BOARD_LED_PIN, BOARD_BUTTON_PIN, BOARD_JTMS_SWDIO_PIN,
    BOARD_JTCK_SWCLK_PIN, BOARD_JTDI_PIN, BOARD_JTDO_PIN, BOARD_NJTRST_PIN,
    56, 58, 59, 61, 62, 64, 65, 67, 68, 70, 71, 73, 74, 76, 77, 78, 79, 81,
    82, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100
};


#endif
