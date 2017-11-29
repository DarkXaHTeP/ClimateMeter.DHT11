FROM arm32v7/debian:stretch

WORKDIR /app

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
    apk add --no-cache git build-essential

RUN git clone git://git.drogon.net/wiringPi

# RUN ln -s /usr/include/sys /usr/include/asm

# RUN sed -i 's|$(LDCONFIG)|$(LDCONFIG /app/wiringPi/wiringPi)|g' /app/wiringPi/wiringPi/Makefile

RUN cd ./wiringPi/wiringPi/ && make -j5

COPY ./src ./src

RUN cd ./wiringPi/wiringPi && cp wiringPi.o wiringSerial.o wiringShift.o piHiPri.o piThread.o wiringPiSPI.o wiringPiI2C.o softPwm.o softTone.o mcp23008.o mcp23016.o mcp23017.o mcp23s08.o mcp23s17.o sr595.o pcf8574.o pcf8591.o mcp3002.o mcp3004.o mcp4802.o mcp3422.o max31855.o max5322.o ads1115.o sn3218.o bmp180.o htu21d.o ds18b20.o rht03.o drcSerial.o drcNet.o pseudoPins.o wpiExtensions.o ../../src

RUN cd ./src && gcc -c -I../wiringPi/wiringPi -fPIC dht11.c -o dht11.o

RUN cd ./src && gcc -shared dht11.o wiringPi.o wiringSerial.o wiringShift.o piHiPri.o piThread.o wiringPiSPI.o wiringPiI2C.o softPwm.o softTone.o mcp23008.o mcp23016.o mcp23017.o mcp23s08.o mcp23s17.o sr595.o pcf8574.o pcf8591.o mcp3002.o mcp3004.o mcp4802.o mcp3422.o max31855.o max5322.o ads1115.o sn3218.o bmp180.o htu21d.o ds18b20.o rht03.o drcSerial.o drcNet.o pseudoPins.o wpiExtensions.o -o libdht11.so

RUN cd ./src && cp ./dht11.h /usr/include && cp ./libdht11.so /usr/lib

RUN rm -rf ./wiringPi && rm -rf ./src

COPY ./reader ./reader

RUN cd ./reader && gcc ./reader.c -o ./reader -l dht11

# RUN apk del git alpine-sdk linux-headers

CMD [ "./reader/reader" ]
