/* hm3301.cpp
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

#include "hm3301.h"

using namespace std;

Hm3301::Hm3301( const char* busFile, uint8_t i2cAddress )
{
    fd_ = open( busFile, O_RDWR );

    ioctl( fd_, I2C_SLAVE, i2cAddress );
    usleep( 1000 );
}

void
Hm3301::readData()
{
    
    if ( i2c_smbus_write_byte( fd_, 0x88 ) < 0 )
    {
        cerr << "Write error" << endl;
    }

    if ( read(fd_, data_+1, sizeof(data_)-1) < 0 )
    {
        cerr << "Read error" << endl;
    }
    
    for ( int i=0; i < 30; i++ )
    {
        cout << hex << static_cast<int>(data_[i]) << " ";;
    }

    cout << dec << endl;

    raw_ = reinterpret_cast<const Raw_*>(data_+2);
}

float
Hm3301::spm010() const
{
    return static_cast<float>(ntohs(raw_->spm010))/1000.0f;
}

float
Hm3301::spm025() const
{
    return static_cast<float>(ntohs(raw_->spm025))/1000.0f;
}

float
Hm3301::spm100() const
{
    return static_cast<float>(ntohs(raw_->spm100))/1000.0f;
}

float
Hm3301::apm010() const
{
    return static_cast<float>(ntohs(raw_->apm010))/1000.0f;
}

float
Hm3301::apm025() const
{
    return static_cast<float>(ntohs(raw_->apm025))/1000.0f;
}

float
Hm3301::apm100() const
{
    return static_cast<float>(ntohs(raw_->apm100))/1000.0f;
}
