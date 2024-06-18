#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "radio_public.h"
#include "radio_trace.h"
#include "star_gpio.h"
#include "star_protocol.h"
#include "star_driver.h"

#define I2C_SLAVE_ADDRESS   0x61
#define ST_WRITE_BYTES_MAX  1024

int main(void)
{
    Tun_Status tunerStatus = RET_ERROR;

    unsigned char read_data[4];
    memset(read_data, 0, 4);

    printf("2024. 6. 13 #2\n");

    star_tuner_reset();

    star_i2c_open();

    tunerStatus = Star_I2C_Direct_Read(I2C_SLAVE_ADDRESS, STAR_ADDRESS_PRECHECKING, read_data, 4);

    if (tunerStatus != RET_SUCCESS)
    {
        printf("Star_I2C_Direct_Read fail\n");
        return -1;
    }

    printf("STAR_ADDRESS_PRECHECKING result : %02x %02x %02x %02x\n", read_data[0], read_data[1], read_data[2], read_data[3]);

    tunerStatus = TUN_Download_BootCode(I2C_SLAVE_ADDRESS);

    if (tunerStatus != RET_SUCCESS)
    {
        printf("TUN_Download_BootCode fail\n");
        return -1;
    }

    star_i2c_close();

    return 0;
}

