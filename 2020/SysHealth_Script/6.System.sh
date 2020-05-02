#/bin/bash
Time=`date +%Y-%m-%d__%H:%M:%S`
HostName=`hostname`
OsType=`cat /etc/os-release | head -n 1 | tr "\"" " " | cut -d " " -f 2-`
KernelVersion=`uname -r`
LoadAvg=`cat /proc/loadavg | cut -d " " -f 1-3`
Uptime=`uptime -p | tr -s " " "_"`

eval $(df -T -x devtmpfs -x tmpfs -m --total | tail -n 1 | awk \
    '{printf("DiskToTal=%d;DiskUsed=%d;",$3,$4)}')

#echo "${DiskToTal} ${DiskUsed}"

DiskUsedP=$[ ${DiskUsed} * 100 / ${DiskToTal} ]
#echo ${DiskUsedP}
DiskWarningLevel="normal"
if [[ ${DiskUsedP} -gt 90 ]]; then
    DiskWarningLevel="warning"
elif [[ ${DiskUsedP} -gt 80 ]]; then
    DiskWarningLevel="note"
fi

eval $(free -m | head -n 2 | tail -n 1 | awk \
    '{printf("MemTotal=%d;MemUsed=%d;", $2, $3)}')

MemUsedP=$[ ${MemUsed} * 100 / ${MemTotal} ]

MemWarningLevel="normal"
if [[ ${MemUsedP} -gt 80 ]]; then
    MemWarningLevel="warning"
elif [[ ${DiskUsedP} -gt 70 ]]; then
    MemWarningLevel="note"
fi

CpuTemp=`cat /sys/class/thermal/thermal_zone0/temp`
CpuTemp=`echo "scale=2;${CpuTemp}/1000" | bc`

CpuWarningLevel="normal"
if [[ `echo "${CpuTemp} >= 70" | bc -l` -eq 1 ]]; then
    CpuWarningLevel="note"
elif [[ `echo "${CpuTemp} >= 50" | bc -l` -eq 1 ]]; then 
        CpuWarningLevel="warning"
fi

echo "${Time} ${HostName} ${OsType} ${KernelVersion} ${Uptime} ${LoadAvg} ${DiskToTal} ${DiskUsedP}% ${MemTotal} ${MemUsedP}% ${CpuTemp} ${DiskWarningLevel} ${MemWarningLevel} ${CpuWarningLevel}"
