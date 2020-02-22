#!/bin/bash
echo "this is the first trap"
trap "echo 'hello new year'" SIGINT
sleep 3
echo "remove trap"
trap -- SIGINT
sleep 3
echo "end"
