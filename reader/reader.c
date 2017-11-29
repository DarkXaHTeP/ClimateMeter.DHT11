#include <dht11.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
		if ( retry_read_dht11_data(360) == 1)
        {
            printf("Humidity = %f %% Temperature = %f *C\n", get_humidity(), get_temp());
        }
        else
        {
            printf("Data is not good, skipping\n");
        }

		usleep( 1000 * 1000); /* wait 1sec to refresh */
	}

	return(0);
}