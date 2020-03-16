#!/bin/bash
a=10
if [[ ${a:+1} ]]; then
    echo "exist"
else 
    echo "not exist"
fi
let a=${a}+10
a=$(( ${a}+10 ))
echo "a=${a}"
