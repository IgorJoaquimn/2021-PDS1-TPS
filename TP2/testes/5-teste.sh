#!/bin/bash
clear

# Carrega o gcc com o primeiro argumento passado no terminal
gcc "$1"

# Executa o arquivo compilado pelo gcc
./a.out caso-teste/input.txt 5

# Apaga o arquivo resultante
rm a.out