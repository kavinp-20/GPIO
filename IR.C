#include "ir_sensor.h"


volatile uint8_t *ddr = (uint8_t *)0x30;
volatile uint8_t *port = (uint8_t *)0x31;
volatile uint8_t *pin = (uint8_t *)0x2F;


#define IR_BIT 0

void ir_init(void)
{
    
    *ddr &= ~(1 << IR_BIT);

    
    *port &= ~(1 << IR_BIT); /*PULL UP OFF*/
}

uint8_t ir_read(void)
{
    return ((*pin >> IR_BIT) & 1);
}
