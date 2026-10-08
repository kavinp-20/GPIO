#include "ir_sensor.h"

/* PORT F */
volatile uint8_t *ddr = (uint8_t *)0x30;
volatile uint8_t *port = (uint8_t *)0x31;
volatile uint8_t *pin = (uint8_t *)0x2F;

/* IR sensor connected to PF0 */
#define IR_BIT 0

void ir_init(void)
{
    /* PF0 as INPUT */
    *ddr &= ~(1 << IR_BIT);

    /* Pull-up OFF */
    *port &= ~(1 << IR_BIT);
}

uint8_t ir_read(void)
{
    return ((*pin >> IR_BIT) & 1);
}
