FROM arm32v6/alpine:3.6

WORKDIR /app

RUN apk add --no-cache git alpine-sdk linux-headers

RUN git clone git://git.drogon.net/wiringPi

RUN ln -s /usr/include/sys /usr/include/asm

RUN make -C ./wiringPi/wiringPi static CFLAGS="$CFLAGS -I." LDFLAGS="$LDFLAGS" || return 1

COPY ./src .
RUN gcc -x c ./dht_reader.c -I./wiringPi/wiringPi -L./wiringPi/wiringPi -l wiringPi -o dht_reader
RUN gcc -x c ./dht_reader.c -I./wiringPi/wiringPi -L./wiringPi/wiringPi -l wiringPi -static -o dht_reader2

ENTRYPOINT [ "./dht_reader" ]
