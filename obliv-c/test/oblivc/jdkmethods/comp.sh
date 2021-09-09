#!/bin/sh
../../..//bin/oblivcc --save-temps -fPIC -DREMOTE_HOST=localhost -O3 -I . jdkmethodsoc.oc jdkmethods.c ../common/util.c
cp jdkmethodsoc.o /home/openjdk/obliv-c/_build/
