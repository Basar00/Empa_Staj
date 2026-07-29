#include "debug0.h"
#include <stdio.h>
#include <stdint.h>

extern void PRV_SCU_CLK_Init(void);

//2.
void bit_set(uint8_t *reg, uint8_t bit) {
    *reg |= (1 << bit);
}
//3.
void bit_clear(uint8_t *reg, uint8_t bit) {
    *reg &= ~(1 << bit);
}
//4.
void bit_toggle(uint8_t *reg, uint8_t bit) {
    *reg ^= (1 << bit);
}
//5.
uint8_t bit_read(uint8_t reg, uint8_t bit) {
    return (reg & (1 << bit)) ? 1 : 0;
}

void PRV_USER_Code(void)
{
    char buffer[128];
    uint8_t control_reg = 0x00;

    PRV_SCU_CLK_Init();
        My_Debug_Init();


    My_Debug_Print("\r\n---------------------------------------\r\n");

    sprintf(buffer, "Initial Register = 0x%02X\r\n", control_reg);
    My_Debug_Print(buffer);

    // ENABLE SET (Bit 0)
    bit_set(&control_reg, 0);
    sprintf(buffer, "ENABLE SET -> Register = 0x%02X\r\n", control_reg);
    My_Debug_Print(buffer);

    // ERROR CLEAR (Bit 1)
    bit_clear(&control_reg, 1);

    // MODE = TX (Bit 3 SET, Bit 2 CLEAR)
    control_reg &= ~(0x03 << 2);
    control_reg |= (2 << 2);
    sprintf(buffer, "MODE = TX -> Register = 0x%02X\r\n", control_reg);
    My_Debug_Print(buffer);

    // DATA_READY TOGGLE (Bit 4)
    bit_toggle(&control_reg, 4);
    sprintf(buffer, "DATA_READY TOGGLE -> Register = 0x%02X\r\n", control_reg);
    My_Debug_Print(buffer);

    // READ Kontrolü
    if (bit_read(control_reg, 4)) {
        My_Debug_Print("DATA_READY Biti (Bit 4) Aktif (1)\r\n");
    } else {
        My_Debug_Print("DATA_READY Biti (Bit 4) Pasif (0)\r\n");
    }

    My_Debug_Print("---------------------------------------\r\n");

    while(1){

    }
}
