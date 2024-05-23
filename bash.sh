#!/bin/bash
#gcc my_copy.c -o flame_cp 

./flame_cp "$@" 

# Check
exit_code=$?
if [ $exit_code -eq 0 ]; then
    echo "Copy successful."
elif [ $exit_code -eq 2 ]; then
    echo "Invalid flags. Usage: ./flame_cp -i <source_file> -o <destination_file>"
elif [ $exit_code -eq 3 ]; then
    echo "Could not locate input file."
elif [ $exit_code -eq 4 ]; then
    echo "Error in creating or writing output file. File already exists"
else
    echo "Unknown error."
fi
