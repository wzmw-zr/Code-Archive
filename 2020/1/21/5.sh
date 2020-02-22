#!/bin/bash
get_num() {
    arg_list=$*
    arg_num=$#
    echo "arg_num=${arg_num}"
    for arg in ${arg_list}; do
        echo ${arg}
    done
}
a=$*
get_num ${a} 
