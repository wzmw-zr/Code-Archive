#!/bin/bash
IFS=$'\n'
declare -a PID_List
declare -a Process_Runtime_pre
declare -a ProcessName
declare -a User_List
declare -a Mem_List
Number=0

for line in `ps -aux | grep -v USER`; do 
    Line=`echo ${line} | tr -s " "`
    User=`echo ${Line} | cut -d " " -f 1`
    PID=`echo ${Line} | cut -d " " -f 2`
    Name=`echo ${Line} | cut -d " " -f 11`
    Mem=`echo ${Line} | cut -d " " -f 4`
    #echo "${User} ${PID} ${Name} ${Mem}"
    Process_File="/proc/${PID}/stat"
    FileContent=`cat ${Process_File} 2>/dev/null`
    if [[ -z ${FileContent} ]]; then
        continue
    fi
    utime=`echo ${FileContent} | cut -d " " -f 14`
    stime=`echo ${FileContent} | cut -d " " -f 15`
    cutime=`echo ${FileContent} | cut -d " " -f 16`
    cstime=`echo ${FileContent} | cut -d " " -f 17`
    #echo "${utime} ${stime} ${cutime} ${cstime}"
    Total_Time_Pre=$[ ${utime} + ${stime} + ${cutime} + ${cstime} ]
    PID_List[${Number}]=${PID}
    Process_Runtime_pre[${Number}]=${Total_Time_Pre}
    ProcessName[${Number}]=${Name}
    User_List[${Number}]=${User}
    Mem_List[${Number}]=${Mem}
    Number=$[ ${Number} + 1 ]
done

sleep 5


Time=`date +%Y-%m-%d__%H:%M:%S`

USER_HZ=`getconf CLK_TCK`


for i in `seq 0 $[ ${Number} - 1 ]`; do
    PID=${PID_List[${i}]}
    Process_File="/proc/${PID}/stat"
    FileContent=`cat ${Process_File} 2>/dev/null`
    if [[ -z ${FileContent} ]]; then
        continue
    fi
    utime=`echo ${FileContent} | cut -d " " -f 14`
    stime=`echo ${FileContent} | cut -d " " -f 15`
    cutime=`echo ${FileContent} | cut -d " " -f 16`
    cstime=`echo ${FileContent} | cut -d " " -f 17`
    Total_Time_after=$[ ${utime} + ${stime} + ${cutime} + ${cstime} ]
    Total_Time=$[ ${Total_Time_after} - ${Total_Time_Pre} ]
    echo ${Total_Time}
    Total_Time_Percent=`echo "scale=2;${Total_Time} / 5000" | bc`
    if [[ ${Total_Time} -gt 2500 ]]; then
        echo "${Time} ${ProcessName[${i}]} ${PID} ${User_List[${i}]} ${Total_Time_Percent} ${Mem_List[${i}]}" 
        continue
    fi
    Mem_Percent=`echo ${Mem_List[${i}]} | cut -d "." -f 1`
    if [[ ${Mem_Percent} -ge 50 ]]; then
        echo "${Time} ${ProcessName[${i}]} ${PID} ${User_List[${i}]} ${Total_Time_Percent} ${Mem_List[${i}]}" 
        continue
    fi
    #Process_Runtime_after[${Number}]=${Total_Time_after}
done


echo ${PID}
