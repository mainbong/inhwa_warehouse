#!/bin/bash

filetype=$1
echo "File Type is '$filetype'."
shift
regex=$*
echo "RegEx to find is '$regex'."

find . -name "*.$filetype"| xargs egrep --color -n $regex
