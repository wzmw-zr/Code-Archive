#!/bin/bash
if [[ $# -ne 1 ]]; then
    echo "Invaild Argument"
else 
    git add *
    git commit -m ${1}
    git push
fi
