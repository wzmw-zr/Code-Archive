#!/bin/bash
Time=`date +%Y-%m:%d__%H:%M:%S`
HostName=`cat /etc/hostname`
echo "HostName ${HostName}"

#OLDIFS=${IFS}
#IFS=$'\n'

OS_Version=`cat /etc/os-release | grep PRETTY_NAME | cut -d "=" -f 2 | cut -d "\"" -f 2`
echo "OS_Version ${OS_Version}"

Kernel_Info=`cat /proc/version | cut -d " " -f 3`
echo "Kernel_Info ${Kernel_Info}"

Uptime=`cat /proc/uptime | cut -d " " -f 1`
minute=60
hour=3600
day=86400
Day=`echo "scale=0;${Uptime} / ${day}" | bc`
Hour=`echo "scale=0;(${Uptime} % ${day}) / ${hour}" | bc`
Minute=`echo "scale=0;((${Uptime} % ${day}) % ${hour}) / ${minute}" | bc`
echo "${Day} ${Hour} ${Minute}"

Load=(`cat /proc/loadavg`)
Load_1=${Load[0]}
Load_5=${Load[1]}
Load_15=${Load[2]}
echo "${Load_1} ${Load_5} ${Load_15}"

#IFS=$' '
DiskInfo=(`df -mT | grep ext4`)
DiskTotal=${DiskInfo[2]}
echo "DiskTotal ${DiskTotal}"
DiskUsed=${DiskInfo[3]}
echo "DiskUsed ${DiskUsed}"
DiskUsage=`echo "scale=0;100 * ${DiskUsed} / ${DiskTotal}" | bc`
echo "DiskUsage ${DiskUsage}"
DiskState=""
if [[ (${DiskUsage} -ge 0) && (${DiskUsage} -le 80) ]]; then
    DiskState="normal"
fi

if [[ (${DiskUsage} -gt 80) && (${DiskUsage} -le 90) ]]; then
    DiskState="note"
fi

if [[ ${DiskUsage} -gt 90 ]]; then
    DiskState="warning"
fi

echo ${DiskState}
