#!/bin/bash
a=30
for (( i = 1; i <= ${a}; i++ )); do
    Name="file${i}"
    touch ${Name}
done
Name=(`ls file* | xargs echo`)
for (( i = 0; i < ${#Name[@]}; i++ )); do
    ls -al ${Name[${i}]}
    chown root:zr ${Name[${i}]}
done
echo -e "\nchange!\n"
for (( i = 0; i < ${#Name[@]}; i++ )); do
    ls -al ${Name[${i}]}
done
rm file*
