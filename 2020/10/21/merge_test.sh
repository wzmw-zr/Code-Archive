#!/bin/bash
a=100

while [[ ${a} -gt 0 ]]; do
    `./merge_sort < input`
    a=$[ ${a}-1 ]
done
