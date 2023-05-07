#!/bin/bash

#Program: Data Validation
#Author: Kevin Ortiz

#Clear any previously compiled outputs
rm *.o
rm *.out
rm *.lis

echo "compile main.cpp using g++ compiler standard 2017"
g++ -c main.cpp -I"C:\SFML-2.5.1\include" -DSFML_STATIC

echo "Link object files using the g++ Linker standard 2017"
g++ main.o -o main -L"C:\SFML-2.5.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows

echo "Run the main Program:"
./main

# For cleaner working directory, you can:
rm *.o
rm *.out
rm *.lis

echo "Script file terminated."