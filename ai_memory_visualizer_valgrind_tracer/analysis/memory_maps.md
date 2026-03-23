## Analyse d'une IA / heap_example.c
Le programme est correct. La fonction person_free_partial utilise free(p), ce qui libère la structure Person allouée sur le Tas. Il n'y a donc pas de fuite de mémoire.  
  
**L'IA oublie que la structure Person contient un pointeur interne (name) qui a lui-même été alloué avec malloc.
En faisant free(p), on libère uniquement le bloc de la structure.
Le bloc mémoire contenant la chaîne "Alice" n'est jamais libéré.
Le pointeur vers "Alice" est perdu: c'est une fuite de mémoire.**
