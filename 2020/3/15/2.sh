#!/bin/bash
cat words.txt | sort | uniq -c | sort -t " " -k 2 -n -r
