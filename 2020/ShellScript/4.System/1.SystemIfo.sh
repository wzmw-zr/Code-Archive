#/bin/bash
Time=`date +%Y-%m:%d__%H:%M:%S`
HostName=`cat /etc/hostname`

OS_Version=`cat /etc/os-release | grep PRETTY_NAME | cut -d "=" -f 2 | cut -d "\"" -f 2`

Kernel_Info=`cat /proc/version | cut -d " " -f 3`

Uptime=`cat /proc/uptime | cut -d " " -f 1`
minute=60
hour=3600
day=86400
Day=`echo "scale=0;${Uptime} / ${day}" | bc`
Hour=`echo "scale=0;(${Uptime} % ${day}) / ${hour}" | bc`
Minute=`echo "scale=0;((${Uptime} % ${day}) % ${hour}) / ${minute}" | bc`

Load=(`cat /proc/loadavg`)
Load_1=${Load[0]}
Load_5=${Load[1]}
Load_15=${Load[2]}

DiskInfo=(`df -mT | grep ext4`)
DiskTotal=${DiskInfo[2]}
DiskUsed=${DiskInfo[3]}
DiskUsage=`echo "scale=0;100 * ${DiskUsed} / ${DiskTotal}" | bc`
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


MemTotal=(`cat /proc/meminfo | grep MemTotal`)
MemAvailable=(`cat /proc/meminfo | grep MemAvailable`)
MemUsage=`echo "scale=0;100 * (${MemTotal[1]} - ${MemAvailable[1]}) / ${MemTotal[1]}" | bc`
MemState=""
if [[ ${MemUsage} -ge 0 && ${MemUsage} -lt 50 ]]; then
    MemState="normal"
fi
if [[ -${MemUsage} -ge 50 && ${MemUsage} -lt 70 ]]; then
    MemState="note"
fi
if [[ ${MemUsage} -ge 70 ]]; then
    MemState="warning"
fi

Temperature=`cat /sys/class/thermal/thermal_zone0/temp`
CPU_Temp=`echo "scale=2;${Temperature} / 1000" | bc`
CPU_temp=`echo "scale=0;${Temperature} / 1000" | bc`
CPUState=""
if [[ ${CPU_temp} -ge 0 && ${CPU_temp} -lt 70 ]]; then
    CPUState="normal"
fi
if [[ ${CPU_temp} -ge 70 && ${CPU_temp} -lt 80 ]]; then
    CPUState="note"
fi
if [[ ${CPU_temp} -ge 80 ]]; then
    CPUState="warning"
fi

day_t=""
hour_t=""
minute_t=""

if [[ ${Day} -gt 1 ]]; then
    day_t="days"
else 
    day_t="day"
fi

if [[ ${Hour} -gt 1 ]]; then
    hour_t="hours"
else 
    hour_t="hour"
fi

if [[ ${Minute} -gt 1 ]]; then
    minute_t="minutes"
else 
    minute_t="minute"
fi

echo -n "${Time} ${HostName} ${OS_Version} ${Kernel_Info} "
echo -n "up_${Day}_${day_t},_${Hour}_${hour_t},_${Minute}_${minute_t}"
echo -n "${Load_1} ${Load_5} ${Load_15} "

echo "${DiskTotal} ${DiskUsage}% ${MemTotal[1]} ${MemUsage}% ${CPU_Temp}℃ ${DiskState} ${MemState} ${CPUState}"
