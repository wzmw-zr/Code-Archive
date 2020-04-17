#!/bin/bash
ArgNum=$#
if [[ ${ArgNum} -ne 1 ]]; then
    echo "Invalid Argument : MemLog LastDynamicPercent"
else 
    LastDPercent=$1
    Time=`date +%Y-%m-%d__%H:%M:%S`
    Mem=(`free -m`)
    AllMem=${Mem[7]}
    UsedMem=${Mem[8]}
    RestMem=$[ ${AllMem} - ${UsedMem} ]
    UsedPercent=`echo "scale=1;100 * ${UsedMem} / ${AllMem}" | bc`
    DynamicUsedPercent=`echo "scale=1;0.3 * ${LastDPercent} + 0.7 * ${UsedPercent}" | bc`
    echo "${Time} ${AllMem}M ${RestMem}M ${UsedPercent}% ${DynamicUsedPercent}%"
fi
