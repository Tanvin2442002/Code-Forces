#!/usr/bin/env bash

# ./stress.sh <your_program> <slow_program> gen <number_of_tests>

g++ -g "$1".cpp -o "$1"
g++ -g "$2".cpp -o "$2"
g++ -g "$3".cpp -o "$3"
 
for ((testNum=0;testNum<$4;testNum++))
do
    ./$3 > input
    ./$2 < input > outSlow
    ./$1 < input > outWrong
    H1=`md5sum outWrong`
    H2=`md5sum outSlow`
    if !(cmp -s "outWrong" "outSlow")
    then
        echo "Error found!"
        echo "Input:"
        cat input
        echo "Wrong Output:"
        cat outWrong
        echo "Slow Output:"
        cat outSlow
        exit
    fi
done
echo Passed $4 tests