#!/bin/bash
clear

# Carrega o gcc com o primeiro argumento passado no terminal
gcc teste.c

# Executa o arquivo compilado pelo gcc

./a.out

# printf "3
# João 50 NULL
# Maria 27 João
# Joana 6 Maria
# " |./a.out

# printf "5
# João 50 NULL
# Carlos 30 João
# Maria 27 João
# Joana 6 Maria
# Gisele 2 Maria
# " |./a.out

# printf "5
# João 50 NULL
# Maria 27 João
# Joana 6 Maria
# Carlos 30 João
# Gisele 2 Maria
# 3
# Gisele João
# Carlos João
# Joana Maria
# " |./a.out

# Apaga o arquivo resultante
rm a.out