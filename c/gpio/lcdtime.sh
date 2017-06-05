#!/bin/bash

process=`ps -ef|grep lcd12864|grep -v grep|awk '{ print $2}'`
for i in $process
do
  echo "Kill the process [ $i ]"
  kill -9 $i
done

/home/pi/test/c/gpio/lcd12864&echo "restart done"
