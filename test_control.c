#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "star_public.h"
#include "star_protocol.h"
#include "star_driver.h"

int main(void)
{
    stTUNER_DRV_CONFIG_t conf;

    int ret = 0;

    printf("2024. 7. 2 #1 test\n");

    star_i2c_open();

    conf.area = eTUNER_DRV_CONF_AREA_NA;
    conf.initMode = eTUNER_DRV_FM_MODE;
    conf.initFreq = 87500;//RHAL_FM_INIT_FREQ;

    ret = star_open(conf);

    if (ret == RET_SUCCESS)
    {
        printf("star_open success.\n");
    }
    else
    {
        printf("star_open fail.\n");
    }

    star_i2c_close();

    return 0;
}

