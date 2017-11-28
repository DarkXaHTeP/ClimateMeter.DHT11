#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <dht11.h>

int main( void )
{
	printf( "Raspberry Pi wiringPi DHT11 Temperature test program\n" );

	if ( init_dht11(7) == 0 )
    {
        printf( "Unable to initialize dht library\n" );
		exit( 1 );
    }

	while ( 1 )
	{
		if ( read_dht11_data() == 1)
        {
            printf("Humidity = %f %% Temperature = %f *C\n", get_humidity(), get_temp());
        }
        else
        {
            printf("Data is not good, skipping\n");
        }

		delay( 1000 ); /* wait 1sec to refresh */
	}

	return(0);
}