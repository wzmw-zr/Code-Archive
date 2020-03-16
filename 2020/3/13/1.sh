#!/bin/bash
Len=$#
a=$*
b=$@
echo ${a}
echo ${b}
declare -p a
declare -p b
