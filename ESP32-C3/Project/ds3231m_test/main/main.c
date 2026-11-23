#include <stdio.h>
#include <stdint.h>
#include "driver/i2c_master.h"

//I2C Configuration: https://docs.espressif.com/projects/esp-idf/en/v5.0/esp32c3/api-reference/peripherals/i2c.html#_CPPv418i2c_driver_install10i2c_port_t10i2c_mode_t6size_t6size_ti

#define I2C_MASTER_SDA_GPIO_PIN 8
#define I2C_MASTER_SCL_GPIO_PIN 9
#define I2C_MASTER_CLOCK_FREQ_HZ 100000 

static i2c_mode_t i2c_mode = I2C_MODE_MASTER;
uint16_t i2c_master_port = 0;


void app_main(void)
{
    // --------initialize I2C--------- 

    //config struct
    const i2c_config_t conf = {
    .mode = i2c_mode,
    .sda_io_num = I2C_MASTER_SDA_GPIO_PIN,         // select GPIO specific to your project
    .sda_pullup_en = GPIO_PULLUP_ENABLE,
    .scl_io_num = I2C_MASTER_SCL_GPIO_PIN,         // select GPIO specific to your project
    .scl_pullup_en = GPIO_PULLUP_ENABLE,
    .master.clk_speed = I2C_MASTER_CLOCK_FREQ_HZ,  // select frequency specific to your project
    .clk_flags = 0,                          // you can use I2C_SCLK_SRC_FLAG_* flags to choose i2c source clock here
};

    //configuration
    ESP_ERROR_CHECK(i2c_param_config(i2c_master_port), &conf);

    //install the driver ---LEFT OFF ON INTR_ALLOC_FLAGS---
    ESP_ERROR_CHECK(i2c_driver_install(I2C_NUM_0, i2c_mode, int intr_alloc_flags));

    //"After installing the I2C driver, ESP32-C3 is ready to communicate with other I2C devices." -- from I2C documentation linked above

    // -------- finished initializing I2C---------

    
}
