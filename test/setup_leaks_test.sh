#!/bin/bash

mv ../main.c main_fillit.c
cp main_fillit_leaks_test.c ../main.c
make re -C ../
