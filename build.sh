#!/usr/bin/env bash

echo "Using next versions:"
gcc -v
gpio -v

mkdir build
gcc -o build/dht_reader src/dht_reader.c -l wiringPi
