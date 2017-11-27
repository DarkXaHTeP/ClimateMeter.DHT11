#!/usr/bin/env bash

echo "Using next versions:"
gcc -v
gpio -v

gcc -o dht_reader dht_reader.c -l wiringPi
