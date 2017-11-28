#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXTIMINGS	85

int dht_pin;

int dht11_dat[5] = { 0, 0, 0, 0, 0 };

float temperature = 0.0;
float humidity = 0.0;

char buffer[10];

int init_dht11(int pin)
{
    dht_pin = pin;

    if ( wiringPiSetup() == -1 )
    {
        return 0;
    } else {
        return 1;
    }
}

float get_temp()
{
    return temperature;
}

float get_humidity()
{
    return humidity;
}

int read_dht11_data()
{
	uint8_t laststate	= HIGH;
	uint8_t counter		= 0;
	uint8_t j		= 0, i;
	float	f; /* fahrenheit */

	dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;

	/* pull pin down for 18 milliseconds */
	pinMode( dht_pin, OUTPUT );
	digitalWrite( dht_pin, LOW );
	delay( 18 );
	/* then pull it up for 40 microseconds */
	digitalWrite( dht_pin, HIGH );
	delayMicroseconds( 40 );
	/* prepare to read the pin */
	pinMode( dht_pin, INPUT );

	/* detect change and read data */
	for ( i = 0; i < MAXTIMINGS; i++ )
	{
		counter = 0;
		while ( digitalRead( dht_pin ) == laststate )
		{
			counter++;
			delayMicroseconds( 1 );
			if ( counter == 255 )
			{
				break;
			}
		}
		laststate = digitalRead( dht_pin );

		if ( counter == 255 )
			break;

		/* ignore first 3 transitions */
		if ( (i >= 4) && (i % 2 == 0) )
		{
			/* shove each bit into the storage bytes */
			dht11_dat[j / 8] <<= 1;
			if ( counter > 16 )
				dht11_dat[j / 8] |= 1;
			j++;
		}
	}

	/*
	 * check we read 40 bits (8bit x 5 ) + verify checksum in the last byte
	 * print it out if data is good
	 */
	if ( (j >= 40) &&
	     (dht11_dat[4] == ( (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF) ) )
	{
        sprintf(buffer, "%d.%d", dht11_dat[0], dht11_dat[1]);
        humidity = atof(buffer);

        sprintf(buffer, "%d.%d", dht11_dat[2], dht11_dat[3]);
        temperature = atof(buffer);

        return 1;
	} else
    {
		return 0;
	}
}