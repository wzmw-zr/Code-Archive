#!/bin/bash
Times=100
for (( i = 1; i <= ${Times}; i++ )); do
    echo "RANDOM = $[ `date +%s%N` % 1000000000 ]"
done
