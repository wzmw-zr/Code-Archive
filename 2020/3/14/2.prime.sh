#!/bin/bash
declare -a prime
End=1000
sum=0

for i in `seq 2 ${End}`; do 
    if [[ ${prime[${i}]}x == x ]]; then 
        prime[0]=$[ ${prime[0]} + 1 ]
        prime[${prime[0]}]=${i}
        sum=$[ ${sum} + ${i} ]
    fi
    for (( j = 1; j <= ${prime[0]}; j++ )); do
        if [[ $[ ${i} * ${j} ] -gt ${End} ]]; then 
            break
        fi
        prime[$[ ${i} * ${prime[${j}]} ]]=1;
        if [[ $[ ${i} % ${prime[${j}]} ] -eq 0 ]]; then
            break
        fi
    done
done 

echo ${sum}
