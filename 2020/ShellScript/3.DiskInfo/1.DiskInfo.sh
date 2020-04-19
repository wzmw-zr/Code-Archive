#!/bin/bash
OLDIFS=${IFS}
IFS=$'\n'
Time=`date +%Y-%m-%d__%H:%M:%S`
Disk=""
Type=1
Name=""
All=""
Rest=""
Used=""
cnt=0
for line in `df -hmT`; do
    IFS=${OLDIFS}
    Line=(${line})
    if [[ ${Line[1]} = ext4 ]]; then
        Disk=(${line})
        continue
    fi
    Name=${Line[6]}
    All=${Line[2]}
    Rest=${Line[4]}
    Used=${Line[5]}
    if [[ ${cnt} -eq 0 ]]; then
        cnt=$[ ${cnt} + 1 ]
        continue
    fi
    echo "${Time} ${Type} ${Name} ${All} ${Rest} ${Used}"
    IFS=$'\n'
done
Type=0
Name=${Disk[6]}
All=${Disk[2]}
Rest=${Disk[4]}
Used=${Disk[5]}
echo "${Time} ${Type} ${Name} ${All} ${Rest} ${Used}"
