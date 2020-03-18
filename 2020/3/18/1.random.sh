#!/bin/bash
Times=100
for (( i = 1; i <= ${Times}; i++ )); do
    echo "RANDOM = ${RANDOM}"
done
