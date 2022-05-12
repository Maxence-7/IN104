#!/bin/bash

files="interface/clavier.c interface/convert_frequence.c interface/audio.c analyse/getNotes.c analyse/getFreq.c main.c"
gcc -Wall -Wfatal-errors -Werror $files $(gsl-config --cflags --libs) $(sdl2-config --cflags --libs)  -lm
sleep 1
./a.out $1