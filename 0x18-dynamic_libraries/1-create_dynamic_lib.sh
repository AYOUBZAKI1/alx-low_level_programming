#!/bin/bash
gcc -fPIC -o *.c
gcc -shared *.o -o liball.so
