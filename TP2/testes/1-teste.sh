#!/bin/bash
clear

# Carrega o gcc com o primeiro argumento passado no terminal
gcc "$1"

# Executa o arquivo compilado pelo gcc
./a.out caso-teste/input.txt 1 caso-teste/output.txt

# Apaga o arquivo resultante
rm a.out