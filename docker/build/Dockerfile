FROM arm32v6/alpine:3.6

WORKDIR /app

RUN apk add --no-cache git alpine-sdk linux-headers

RUN git clone git://git.drogon.net/wiringPi

RUN ln -s /usr/include/sys /usr/include/asm

RUN sed -i 's|$(LDCONFIG)|$(LDCONFIG /app/wiringPi/wiringPi)|g' /app/wiringPi/wiringPi/Makefile

RUN cd ./wiringPi/wiringPi/ && make -j5 && make -j5 static && make install && make install-static && cd ../..

COPY ./src .
COPY ./reader .
RUN cd /app/src && gcc ./dht11.c -static /usr/lib/wiringPi.a -o dht11.o && cp ./dht11.h /usr/include && cp ./dht11.so /usr/lib && cd ..

CMD [ "./reader/reader" ]
