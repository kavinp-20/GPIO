#include "seg7.h"



volatile uint8_t *ddr[11] =
{
    (uint8_t *)0x21,    /* PORT A */
    (uint8_t *)0x24,    /* PORT B */
    (uint8_t *)0x27,    /* PORT C */
    (uint8_t *)0x2A,    /* PORT D */
    (uint8_t *)0x2D,    /* PORT E */
    (uint8_t *)0x30,    /* PORT F */
    (uint8_t *)0x33,    /* PORT G */
    (uint8_t *)0x101,   /* PORT H */
    (uint8_t *)0x104,   /* PORT J */
    (uint8_t *)0x107,   /* PORT K */
    (uint8_t *)0x10A    /* PORT L */
};

/* PORT registers */

volatile uint8_t *port[11] =
{
    (uint8_t *)0x22,    /* PORT A */
    (uint8_t *)0x25,    /* PORT B */
    (uint8_t *)0x28,    /* PORT C */
    (uint8_t *)0x2B,    /* PORT D */
    (uint8_t *)0x2E,    /* PORT E */
    (uint8_t *)0x31,    /* PORT F */
    (uint8_t *)0x34,    /* PORT G */
    (uint8_t *)0x102,   /* PORT H */
    (uint8_t *)0x105,   /* PORT J */
    (uint8_t *)0x108,   /* PORT K */
    (uint8_t *)0x10B    /* PORT L */
};

/* 7-segment codes */

uint8_t seg_table[10] =
{
    0x3F,   /* 0 */
    0x06,   /* 1 */
    0x5B,   /* 2 */
    0x4F,   /* 3 */
    0x66,   /* 4 */
    0x6D,   /* 5 */
    0x7D,   /* 6 */
    0x07,   /* 7 */
    0x7F,   /* 8 */
    0x6F    /* 9 */
};


void seg7_init(uint8_t p)
{
    *ddr[p] = 0xFF;
    *port[p] = 0x00;
}


void seg7_display(uint8_t p, uint8_t number)
{
    if(number <= 9)
    {
        *port[p] = seg_table[number];
    }
}


void seg7_off(uint8_t p)
{
    *port[p] = 0x00;
}
