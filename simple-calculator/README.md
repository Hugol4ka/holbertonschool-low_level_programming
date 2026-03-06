## Calculatrice en C
Ce programme est une calculatrice interactive dans le terminal écrite en C.
Il propose un menu permettant de choisir une opération arithmétique entre deux nombres.

## Opérations disponibles
Addition
Soustraction
Multiplication
Division
Modulo (bonus)

Le programme demande deux valeurs, effectue l’opération choisie et affiche le résultat avec deux chiffres après la virgule.
La calculatrice fonctionne dans une boucle jusqu’à ce que l’utilisateur sélectionne 0 pour quitter.

## Limitation connue
Si l’utilisateur entre une lettre ou un caractère spécial dans le menu, le programme entre dans une boucle infinie.
Si c'est le cas, utiliser votre clavier en faisant CTRL+C afin de stopper le programme. 

## Compilation
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator

## Exécution
./calculator