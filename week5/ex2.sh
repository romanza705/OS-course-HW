#!/bin/bash
echo 0 > ex2.txt
ln ex2.txt ex2.lock
i=0
while [ $i -le 1000 ]
do
echo "$(($(tail -n 1 < ex2.lock) + 1))" >> ex2.lock
((i++))
done
rm ex2.lock

