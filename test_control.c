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

int main(void)
{
    Tun_Status tunerStatus = RET_ERROR;

    unsigned char read_data[4];

    printf("2024. 6. 28 #2 4096 test\n");

    star_tuner_reset();

    star_i2c_open();

    memset(read_data, 0, 4);
    tunerStatus = Star_I2C_Direct_Read(I2C_SLAVE_ADDRESS, STAR_ADDRESS_PRECHECKING, read_data, 4);

    if (tunerStatus != RET_SUCCESS)
    {
        printf("STAR_ADDRESS_PRECHECKING Star_I2C_Direct_Read fail\n");
        return RET_ERR_I2C_COMM;
    }

    printf("STAR_ADDRESS_PRECHECKING read result : %02x %02x %02x %02x\n", read_data[0], read_data[1], read_data[2], read_data[3]);

    tunerStatus = TUN_Download_BootCode(I2C_SLAVE_ADDRESS);

    if (tunerStatus != RET_SUCCESS)
    {
        printf("TUN_Download_BootCode fail\n");
        return RET_ERR_BOOTCODE;
    }

    usleep(200 * 1000);  // wait 200ms

    memset(read_data, 0 ,4);
    tunerStatus = Star_I2C_Direct_Read(I2C_SLAVE_ADDRESS, STAR_ADDRESS_CMDBUFFER, read_data, 4);

    if (tunerStatus != RET_SUCCESS)
    {
        printf("STAR_ADDRESS_CMDBUFFER Star_I2C_Direct_Read fail\n");
        return RET_ERR_I2C_COMM;
    }

    printf("STAR_ADDRESS_CMDBUFFER read result : %02x %02x %02x %02x\n", read_data[0], read_data[1], read_data[2], read_data[3]);

    //if (read_data[0] == 0xAF && read_data[1] == 0xFE && read_data[2] == 0x42 && read_data[3] == 0x00)
    if ((read_data[0] != 0xAF) || (read_data[1] != 0xFE) || (read_data[2] != 0x42) || (read_data[3] != 0x00))
    {
        return RET_ERR_BOOTCODE;
    }

#if 0
    // set BB IF
    tunerStatus = TUN_Set_BB_IF(I2C_SLAVE_ADDRESS, 0x010000);

    if (tunerStatus != RET_SUCCESS)
    {
        printf("BB IF setting fail (%d)\n", tunerStatus);
        return RET_ERR_I2C_COMM;
    }

    // set Audio IF 
    tunerStatus = TUN_Set_Audio_IF(I2C_SLAVE_ADDRESS, 0x03, 0x000330);

    if (tunerStatus != RET_SUCCESS)
    {
        printf("Audio IF setting fail (%d)\n", tunerStatus);
        return RET_ERR_I2C_COMM;
    }
#endif

    star_i2c_close();

    return 0;
}

