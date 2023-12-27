#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: $0 <filename.cpp>"
    exit 1
fi

filename="$1"

if [ ! -f "$filename" ]; then
    echo "File not found: $filename"
    exit 1
fi

g++ -std=c++11 "$filename" && "./a.out"
