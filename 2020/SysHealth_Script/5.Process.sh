#!/bin/bash
eval $(ps -aux | grep -v PID | awk -v cnt=0 '{if($3>1 || $4>1){printf("Pid_1[%s]=%s;Name1[%s]=%s;Mem1[%s]=%s;Cpu1[%s]=%d;User1[%s]=%s;",cnt, $2, $2, $11, $2, $4, $2, $3, $2, $1);cnt++;}}')
sleep 5
eval $(ps -aux | grep -v PID | awk -v cnt=0 '{if($3>1 || $4>1){printf("Pid_2[%s]=%s;Name2[%s]=%s;Mem2[%s]=%s;Cpu2[%s]=%d;User2[%s]=%s;",cnt,$2, $2, $11, $2, $4, $2, $3, $2, $1);cnt++;}} END{printf("cnt=%d;", cnt);}')

Time=`date +%Y-%m-%d__%H:%M:%S`
cnt=$[ ${cnt} - 1 ]
for (( i = 0; i <= ${cnt}; i++ )); do
    Pid=${Pid_2[${i}]}
    if [[ ${Name1[${Pid}]} = ${Name2[${Pid}]} ]]; then
        echo "${Time} ${Name2[${Pid}]} ${Pid} ${User2[${Pid}]} ${Mem2[${Pid}]}% ${Cpu2[${Pid}]}%"     
    fi
done
