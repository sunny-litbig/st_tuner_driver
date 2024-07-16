#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "star_driver.h"

int main(void)
{
    stTUNER_DRV_CONFIG_t conf;

    int ret = 0;

    printf("2024. 7. 15 #1 test\n");

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
        return -1;
    }

    usleep(200 * 1000); // 200ms wait

    ret = star_setTune(eTUNER_DRV_FM_MODE, 87700, 0, eTUNER_DRV_ID_PRIMARY);

    if (ret != RET_SUCCESS)
        printf("star_tune fail (87700).\n");

    if (ret == RET_SUCCESS)
    {
        ret = star_rds_init(eTUNER_DRV_ID_PRIMARY);

        if (ret == RET_SUCCESS)
        {
            while (1)
            {
                ret = star_rds_read(eTUNER_DRV_ID_PRIMARY);

                if (ret != RET_SUCCESS)
                    break;
        
                usleep(100 * 1000); // 100ms wait
            }
        }
        else
        {
            printf("star_rds_init fail.\n");
        }
    }

    ret = star_close();

    if (ret == RET_SUCCESS)
        printf("star_close success.\n");
    else
        printf("star_close fail.\n");

    return 0;
}

