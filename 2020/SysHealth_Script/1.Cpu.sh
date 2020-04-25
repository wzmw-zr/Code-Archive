#!/bin/bash
Time=`date +%Y-%m-%d__%H:%M:%S`
LoadAvg=`cat /proc/loadavg | cut -d " " -f 1-3`
CpuTemp=`cat /sys/class/thermal/thermal_zone0/temp`
CpuTemp=`echo "scale=2;${CpuTemp} / 1000" | bc`
eval $(head -n 1 /proc/stat | awk -v Sum1=0 '{for (i=2;i<=11;i++){Sum1+=$i} printf("Sum1=%d;idle1=%d", Sum1, $5)}')

sleep 0.5

eval $(head -n 1 /proc/stat | awk -v Sum2=0 '{for (i=2;i<=11;i++){Sum2+=$i} printf("Sum2=%d;idle2=%d",Sum2,$5)}')

CpuUsedPerc=`echo "scale=4;(1-(${idle2}-${idle1}) / (${Sum2}-${Sum1}))*100" | bc`
CpuUsedPerc=`printf "%.2f" ${CpuUsedPerc}`

WarnLevel="normal"

if [[ `echo "${CpuTemp} >= 70" | bc -l` -eq 1 ]]; then
    WarnLevel="warning"
elif [[ `echo "${CpuTemp} >= 50" | bc -l` -eq 1 ]]; then
    WarnLevel="note"
fi

echo "${Time} ${LoadAvg} ${CpuUsedPerc} ${CpuTemp} ${WarnLevel}"
