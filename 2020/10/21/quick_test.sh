#!/bin/bash
a=100

while [[ ${a} -gt 0 ]]; do
    `./quick_sort < input`
    a=$[ ${a}-1 ]
done
