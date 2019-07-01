/* hm3301.h
****************************************************************************************************************
****************************************************************************************************************
    Copyright (C) 2019 Omar Almatov
     
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU General
    Public License as published by the Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.
    
    This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
    implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
    License for more details.
    
    You should have received a copy of the GNU General Public License along with this program. If not, see
    <http://www.gnu.org/licenses/>.
*/

#ifndef HM3301_H_
#define HM3301_H_ 1

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

        //Standard particulate matter
        uint16_t        spm010; 
        uint16_t        spm025; 
        uint16_t        spm100;

        //Atmospheric environment
        uint16_t        apm010; 
        uint16_t        apm025; 
        uint16_t        apm100;   
    };

    int                 fd_;
    uint8_t             data_[ 30 ];
    const Raw_*         raw_;
};

#endif // HM3301_H_
