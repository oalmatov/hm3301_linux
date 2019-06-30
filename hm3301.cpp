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

    //usleep( 100000 );

    if ( read(fd_, data_+1, sizeof(data_)-1) < 0 )
    {
        cerr << "Read error" << endl;
    }
    
    //usleep( 100000 );

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
