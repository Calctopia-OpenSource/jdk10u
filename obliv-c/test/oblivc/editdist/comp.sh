#!/bin/sh
../../..//bin/oblivcc --save-temps -DREMOTE_HOST=localhost -O3 -I . editdistoc.oc editdist.c ../common/util.c
