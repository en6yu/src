#!/bin/sh
mkdir -p $1
if [ $# -gt 0 ];then
    cp ./base/Makefile ./$1
    touch ./$1/"$1".cpp
else
    echo "no param"
fi
sed -i "s/base/$1/g" ./$1/Makefile
sed -i "9s/$/ $1/g" ./Makefile
