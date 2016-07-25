#!/bin/sh

i=0
for f in "$@"; do
    while IFS=, read frame x y
    do
	echo "$frame,$i,$x,$y"
    done < $f
    let "i++"
done
