#!/bin/bash

# Compile all .c files in the current directory into a dynamic library

# Get the list of .c files in the current directory
c_files=$(ls *.c)

# Compile each .c file into an object file
for file in $c_files; do
    gcc -c -fPIC "$file" -o "${file%.c}.o"
done

# Create the dynamic library from the object files
gcc -shared -o liball.so *.o

# Clean up object files
rm *.o
