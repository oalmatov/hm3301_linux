/* ccs811.h
****************************************************************************************************************
****************************************************************************************************************
*/

#include "hm3301.h"

using namespace std;

int main()
{
    Hm3301      hm3301( "/dev/i2c-0", 0x40 );

    hm3301.readData();
    
    cout << "Standard PM1.0\t" << hm3301.spm010() << endl;
    cout << "Standard PM2.5\t" << hm3301.spm025() << endl;
    cout << "Standard PM10\t" << hm3301.spm100() << endl;
    cout << "Atmospheric PM1.0\t" << hm3301.apm010() << endl;
    cout << "Atmospheric PM2.5\t" << hm3301.apm025() << endl;
    cout << "Atmospheric PM10\t" << hm3301.apm100() << endl;
}
