#!/bin/bash
Time=`date +%Y-%m-%d__%H:%M:%S`

eval $(cat /etc/passwd | awk -F ":" -v num=0 '{if($3 >= 1000 && $3 < 65534) {num++; printf("User["num"]=%s;", $1)}}\
END {printf("UserTotal=%d;", num)}')

MostActiveUser=`last -w | awk '{printf("%s\n", $1)}' |grep -v wtmp| grep -v reboot | grep -v "^$" | sort | uniq -c | sort -k 1 -n -r |awk -v num=3 '{if (num>0) printf(" %s,", $2); num--;}' | cut -c 2-`

eval $(awk -F: '{if($3 == 1000) printf("User_1000=%s", $1)}' /etc/passwd)
UserWithRoot=${User_1000}

Users=`cat /etc/group | grep sudo | cut -d : -f 4 | tr ',' ' '`
for i in ${Users}; do
    if [[ ${i} == ${User_1000} ]]; then
        continue
    fi
    UserWithRoot="${UserWithRoot},$i"
done

if [[ -r /etc/sudoers ]]; then
    for i in ${User[*]}; do
        grep -q "^${i}" /etc/sudoers
        if [[ $? -eq 0 ]]; then
            UserWithRoot="${UserWithRoot},${i}"
        fi
    done
fi

UserLogin=`w -h | awk '{printf(",%s_%s_%s", $1, $2, $3);}' | cut -c 2-`

echo "${Time} ${UserTotal} [${MostActiveUser}] [${UserWithRoot}] [${UserLogin}]"

#eval $(who | awk '{ printf("UserName["NR"]=%s;TTY["NR"]=%s;", $1, $2) }\
#    END {printf("Login_User=%s;", NR)}')

#echo -n "["
#for (( i = 1; i <= ${Login_User} && i <= 3; i++ )); do
#    if [[ ${i} -gt 1 ]]; then
#        echo -n ","
    #fi
    #echo -n "${UserName[${i}]}"
#done
#echo -n "]"

#echo -n "["
#who | awk -v num=0 '{if (num > 0) {printf(",");}; num++; printf("%s_%s_%s", $1, $5, $2);}'
#echo "]"
