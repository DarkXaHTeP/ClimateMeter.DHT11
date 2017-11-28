FROM arm32v6/alpine:3.6

WORKDIR /app

RUN apk add --no-cache git alpine-sdk linux-headers

RUN git clone git://git.drogon.net/wiringPi

RUN ln -s /usr/include/sys /usr/include/asm

RUN sed -i 's|$(LDCONFIG)|$(LDCONFIG /app/wiringPi/wiringPi)|g' /app/wiringPi/wiringPi/Makefile

RUN cd ./wiringPi/wiringPi/ && make -j5 && make install && cd ../..

COPY ./src .
RUN gcc ./dht_reader.c -l wiringPi -o dht_reader

ENTRYPOINT [ "./dht_reader" ]
