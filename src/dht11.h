#ifndef _DHT11LIB
    #define _DHT11LIB

    #ifdef __cplusplus
    extern "C" {
    #endif

    extern int init_dht11(int pin);
    extern float get_temp();
    extern float get_humidity();
    extern int read_dht11_data();

    #ifdef __cplusplus
    }
    #endif

#endif