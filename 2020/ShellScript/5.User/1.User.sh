#!/bin/bash
Time=`date +%Y-%m-%d__%H:%M:%S`
echo -n "${Time} "

Normal_User_Id=(`cat /etc/passwd | cut -d ":" -f 3 | sort -n`)
Count=0
for i in `seq 0 $[ ${#Normal_User_Id[@]} - 1 ]`; do
    if [[ (${Normal_User_Id[${i}]} -ge 1000) && (${Normal_User_Id[${i}]} -lt 65534 ) ]]; then
        Count=$[ ${Count} + 1 ]
    fi
done
echo -n "${Count} "

Active_User=(`last | tr -s " " | cut -d " " -f 1 | uniq`)
Number=0
declare -a Active_User_List
for i in `seq 0 $[ ${#Active_User[@]} - 1 ]`; do
    if [[ ${Number} -ge 3 ]]; then
        break
    fi
    flag=0
    if [[ ${#Active_User_List[@]} -eq 0 ]]; then
        Active_User_List[${Number}]=${Active_User[${i}]}
        Number=$[ ${Number} + 1 ]
        continue
    fi
    for j in `seq 0 $[ ${#Active_User_List[@]} - 1 ]`; do
        if [[ ${Active_User[${i}]} = ${Active_User_List[${j}]} ]]; then
            flag=1
        fi
        if [[ ${flag} -eq 1 ]]; then
            break
        fi
    done
    if [[ ${flag} -eq 1 ]]; then
        continue
    else 
        Active_User_List[${Number}]=${Active_User[${i}]}
        Number=$[ ${Number} + 1 ]
    fi
done

echo -n "["
flag=0
for i in `seq 0 $[ ${Number} - 1 ]`; do
    if [[ ${flag} -gt 0 ]]; then
        echo -n ","
    fi
    echo -n "${Active_User_List[${i}]}"
    flag=1
done
echo -n "] "


IFS=$'\n'
declare -a Root_User
for line in `cat /etc/sudoers | grep -E "#" -v | grep -E "%" -v | grep -E "ALL"`; do
    Root_User[${#Root_User[@]}]=`echo ${line} | cut -d " " -f 1`
done

echo -n "["
for i in `seq 0 $[ ${#Root_User[@]} - 1 ]`; do
    if [[ ${i} -gt 0 ]]; then
        echo -n "," 
    fi
    echo -n "${Root_User[${i}]}"
done
echo -n "] "

declare -a Online
echo -n "["
flag=0
for line in `who`; do
    Line=`echo ${line} | tr -s " "`
    Name=`echo ${Line} | cut -d " " -f 1`
    TTY=`echo ${Line} | cut -d " " -f 2`
    IP=`echo ${Line} | cut -d " " -f 5 | tr -d "()"`
    if [[ ${flag} -ge 1 ]]; then
        echo -n ","
    fi
    echo -n "${Name}_${IP}_${TTY}"
    flag=1
done
echo "]"
