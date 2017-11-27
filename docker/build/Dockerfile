FROM arm32v6/alpine:3.6.2

WORKDIR /app

RUN apk add --no-cache git alpine-sdk linux-headers

RUN ln -s /usr/include/sys /usr/include/asm
RUN git clone git://git.drogon.net/wiringPi && cd wiringPi

RUN	make -C wiringPi static CFLAGS="$CFLAGS -I." LDFLAGS="$LDFLAGS" || return 1
RUN	make -C devLib static CFLAGS="$CFLAGS -I../wiringPi" LDFLAGS="$LDFLAGS" || return 1
RUN	make -C gpio CFLAGS="$CFLAGS -I../wiringPi -I../devLib" LDFLAGS="$LDFLAGS -L../wiringPi -L../devLib" || return 1
RUN cd ..
COPY ./src .
RUN gcc -o dht_reader dht_reader.c -l ./wiringPi/wiringPi

ENTRYPOINT [ "./dht_reader" ]