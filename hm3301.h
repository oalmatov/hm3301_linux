// hm3301.h

#ifndef HM3301_H
#define HM3301_H 1

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

class Hm3301
{

public:

                        Hm3301( const char* busFile, uint8_t i2cAddress );

    void                readData();
    float               spm010() const;
    float               spm025() const;
    float               spm100() const;
    float               apm010() const;
    float               apm025() const;
    float               apm100() const;

protected:

    struct Raw_
    {
        uint32_t        sensorNum;
        uint16_t        spm010; //PM 1.0 Standard
        uint16_t        spm025; //PM 2.5 Standard
        uint16_t        spm100; //PM 10.0 Standard
        uint16_t        apm010; //PM 1.0 Atmospheric
        uint16_t        apm025; //PM 2.5 Atmospheric
        uint16_t        apm100; //PM 10.0   
    };

    int                 fd_;
    uint8_t             data_[ 30 ];
    const Raw_*         raw_;
};

#endif // HM3301_H
