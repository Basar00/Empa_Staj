#include "sensirion_i2c_hal.h"
#include "sensirion_common.h"
#include "sensirion_config.h"

#include "hal_i2c.h"
#include "abov_config.h"

void sensirion_i2c_hal_init(void){
    HAL_I2C_Init(I2C_ID_2);
}

void sensirion_i2c_hal_free(void){
}

int8_t sensirion_i2c_hal_write(uint8_t address, const uint8_t* data, uint8_t count)
{
    HAL_ERR_e err = HAL_I2C_Transmit(I2C_ID_2, address, (uint8_t*)data, count, true);
    return (err == HAL_ERR_OK) ? 0 : -1;
}

int8_t sensirion_i2c_hal_read(uint8_t address, uint8_t* data, uint8_t count)
{
    HAL_ERR_e err = HAL_I2C_Receive(I2C_ID_2, address, data, count, true);
    return (err == HAL_ERR_OK) ? 0 : -1;
}
void sensirion_i2c_hal_sleep_usec(uint32_t useconds)
{
    uint32_t cycles = (useconds * 30);
    for (volatile uint32_t i = 0; i < cycles; i++){
}
}
