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

    printf("2024. 7. 1 #4 test\n");

    star_tuner_reset();

    star_i2c_open();

    // for Tunner communication check
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

    usleep(200 * 1000);  // wait 200 ms

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

    tunerStatus = TUN_Download_CustomizedCoeffs(I2C_SLAVE_ADDRESS);

    if (tunerStatus != RET_SUCCESS)
    {
        printf("TUN_Download_CustomizedCoeffs fail\n");
        return RET_ERR_BOOTCODE;
    }
    else
    {
        printf("CustomizedCoeffs has been succefully downloaded.\n");
    }

    // BB SAI setting
    // 0x07 ==> Mode7
    // 0x01 ==> master "half cycle" mode 
    tunerStatus = TUN_conf_BB_SAI(I2C_SLAVE_ADDRESS, 0x07, 0x01);

    if (tunerStatus != RET_SUCCESS)
    {
        printf("BB SAI setup fail (%d)\n", tunerStatus);
        return RET_ERR_I2C_COMM;
    }
    else
    {
        printf("BB SAI setup is complete.\n");
    }

    // set BB IF
    // 0x04 ==> Audio interface mode 4
    // 0x05 ==> Base Band (IF) interface SAI BB split mode 
    tunerStatus = TUN_Set_BB_IF(I2C_SLAVE_ADDRESS, 0x040005);

    if (tunerStatus != RET_SUCCESS)
    {
        printf("BB IF setup fail (%d)\n", tunerStatus);
        return RET_ERR_I2C_COMM;
    }
    else
    {
        printf("BB IF setup is complete.\n");
    }

    // set Audio IF
    // 0x03 ==> audio SAI output enable and DAC enable
    // Bit [23:12] 0xA57 ==> 44.1 kHz, Bit [11:0] 0x310 ==> Bit[5] 0: SAI Audio Data length is 16L + 16R 
    tunerStatus = TUN_Set_Audio_IF(I2C_SLAVE_ADDRESS, 0x03, 0xA57310);

    if (tunerStatus != RET_SUCCESS)
    {
        printf("Audio IF setup fail (%d)\n", tunerStatus);
        return RET_ERR_I2C_COMM;
    }
    else
    {
        printf("Audio IF setup is complete.\n");
    }

    star_i2c_close();

    return 0;
}

