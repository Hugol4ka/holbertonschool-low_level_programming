## Analyse d'une IA / heap_example.c
Le programme est correct. La fonction person_free_partial utilise free(p), ce qui libère la structure Person allouée sur le Tas. Il n'y a donc pas de fuite de mémoire.  
### La bonne analyse a faire/ heap_example.c
L'outil indique definitely lost: 6 bytes in 1 blocks. Ces 6 octets correspondent à "Alice" (5 lettres + \0).
**L'IA oublie que la structure Person contient un pointeur interne (name) qui a lui-même été alloué avec malloc.
En faisant free(p), on libère uniquement le bloc de la structure.
Le bloc mémoire contenant la chaîne "Alice" n'est jamais libéré.
Le pointeur vers "Alice" est perdu: c'est une fuite de mémoire.**
--------------------------------------------------------------------------------------------------------------------------------------------------
## Analyse d'une IA / stack_example.c
Une IA va se dire puisque le rapport valgrind n'affiche aucune erreur, le code est sur. 
==199050== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
### la bonne analyse / stack_example.c
Valgrind ne surveille pas l'usage sémantique de la Stack. Utiliser un pointeur vers une variable locale après sa sortie de scope est un Undefined Behavior. Le fait que les valeurs soient encore "correctes" à l'écran est une coïncidence : la mémoire n'a juste pas encore été écrasée par une autre fonction.