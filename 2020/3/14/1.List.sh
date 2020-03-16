#!/bin/bash
if [[ $# -ne 1 ]]; then 
    echo "Usage: bash List.sh num"
    exit
fi

Names=(`cat names`)
function rand() {
    Max=${#Names[*]}
    Time=`date +%s%N`
    Ind=$[ ${Time} % ${Max} ]
    echo ${Names[Ind]}
}
Name=`rand`
echo ${Name}
