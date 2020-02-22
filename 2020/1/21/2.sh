#!/bin/bash
a=10
b=20
while [[ a -ge 0 || b -ge 0 ]]; do
    echo "a=${a} b=${b}"
    let "a--"
    let "b--"
done > "text.txt"
