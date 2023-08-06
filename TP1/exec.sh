#!/bin/bash
clear

# Carrega o gcc com o primeiro argumento passado no terminal
gcc "$1"

# Executa o arquivo compilado pelo gcc
./a.out

# Apaga o arquivo resultante
rm a.out