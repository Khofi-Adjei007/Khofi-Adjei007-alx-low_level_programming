#!/bin/bash

gcc -c -Wall -Werror -fpic *.c
gcc -shared -o liball.so *.o
rm *.o

echo "liball.so successfully created."
