#!/bin/bash

Time=`date +%Y-%m-%d__%H:%M:%S`

Load=(`cat /proc/loadavg`)

Temperature=`cat /sys/class/thermal/thermal_zone0/temp`
Temp=`echo "scale=2; ${Temperature} / 1000" | bc`
intTemp=`echo "scale=0; ${Temperature} / 1000" | bc`
message="normal"

if [[ ( ${intTemp} -ge 50 ) && ( ${intTemp} -lt 70 ) ]]; then
    message="note"
fi
if [[ ${intTemp} -ge 70 ]]; then
    message="warning"
fi

CpuUsageInfo_Pre=(`cat /proc/stat | head -n 1`)
CpuUsage_Pre=0
Idle_pre=${CpuUsageInfo_Pre[4]}
for i in `seq 1 $[ ${#CpuUsageInfo_Pre[@]} - 1 ]`; do
    CpuUsage_Pre=$[ ${CpuUsageInfo_Pre[${i}]} + ${CpuUsage_Pre} ]
done

sleep 0.5

CpuUsageInfo_After=(`cat /proc/stat | head -n 1`)
CpuUsage_After=0
for i in `seq 1 $[ ${#CpuUsageInfo_After[@]} - 1 ]`; do
    CpuUsage_After=$[ ${CpuUsageInfo_After[${i}]} + ${CpuUsage_After} ]
done
Idle_After=${CpuUsageInfo_After[4]}

total=$[ ${CpuUsage_After} - ${CpuUsage_Pre} ]
idle=$[ ${Idle_After} - ${Idle_pre} ]

percent=`echo "scale=1;100 * $[ ${total} - ${idle} ] / ${total}" | bc`

echo "${Time} ${Load[0]} ${Load[1]} ${Load[2]} ${percent}% ${Temp}℃  ${message}"
#echo ${#CpuUsageInfo_Pre[@]}
