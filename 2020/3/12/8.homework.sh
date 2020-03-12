#!/bin/bash
declare -a arr
declare -a prime
sum=0
for i in `seq 0 1000`; do
    arr[i]=1
    prime[i]=0
done

for i in `seq 2 1000`; do
    if [[ ${arr[${i}]} -ne 0 ]]; then
        prime[$[ ${prime[0]} + 1 ]]=${i}
        prime[0]=$[ ${prime[0]} + 1 ]
        sum=$[ ${sum} + ${i} ]
    fi
    for j in `seq 2 ${prime[0]}`; do
        if [[ $[ ${i} * ${j}] -gt 1000 ]]; then
            break;
        fi
        arr[$[ ${i} * ${j} ]]=0;
        num=$[ ${i} % ${j} ]
        if [[ ${num} -eq 0 ]]; then
            break;
        fi
    done
done

for i in `seq 1 ${prime[0]}`; do
    echo ${prime[${i}]}
done

echo "sum = ${sum}"
