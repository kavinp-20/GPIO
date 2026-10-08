#ifndef SEG7_H
#define SEG7_H

#include <stdint.h>

#define PORT_A  0
#define PORT_B  1
#define PORT_C  2
#define PORT_D  3
#define PORT_E  4
#define PORT_F  5
#define PORT_G  6
#define PORT_H  7
#define PORT_J  8
#define PORT_K  9
#define PORT_L  10

void seg7_init(uint8_t p);
void seg7_display(uint8_t p, uint8_t number);
void seg7_off(uint8_t p);

#endif
