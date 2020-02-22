#!/bin/bash
trap "echo 'this is the first trap'" SIGINT
sleep 5
echo "new"
trap "echo 'this is the second trap'" SIGINT
sleep 5
