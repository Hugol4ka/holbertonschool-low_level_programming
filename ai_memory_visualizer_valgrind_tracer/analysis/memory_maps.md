# Valgrind & Memory Analysis Report

Ce rapport documente l'analyse des comportements mémoire de différents programmes C, en comparant les interprétations limitées d'une IA avec une analyse technique approfondie.

---

## 1. Heap Analysis (`heap_example.c`)

> ** Analyse de l'IA :** > "Le programme est correct. La fonction `person_free_partial` utilise `free(p)`, ce qui libère la structure Person allouée sur le Tas. Il n'y a donc pas de fuite de mémoire."

###  La bonne analyse
L'IA commet une erreur classique de **shallow free** (libération superficielle). 
* **Preuve Valgrind :** L'outil indique `definitely lost: 6 bytes in 1 blocks`. 
* **Explication :** La structure `Person` contient un pointeur interne `name` alloué dynamiquement. En libérant `p` sans libérer `p->name` au préalable, l'adresse de la chaîne "Alice" est perdue. 
* **Conséquence :** Une fuite de mémoire de 6 octets (5 lettres + `\0`).



---

## 2. Stack Analysis (`stack_example.c`)

> **Analyse de l'IA :** > "Puisque le rapport Valgrind n'affiche aucune erreur (`0 errors`), le code est sûr et valide."

###  La bonne analyse
Valgrind a un angle mort ici car il ne surveille pas l'usage sémantique de la Stack.
* **Erreur :** Utiliser un pointeur vers une variable locale après sa sortie de scope.
* **Explication :** C'est un **Undefined Behavior**. Le fait que les valeurs semblent correctes à l'écran est une coïncidence temporelle : la mémoire n'a pas encore été écrasée par une autre stack frame. 
* **Risque :** Dès qu'une autre fonction sera appelée, les données seront corrompues.



---

##  3. Crash Analysis (`crash_example.c`)

> **Analyse de l'IA :** > "Le programme a besoin de plus de mémoire (RAM)."

### La bonne analyse
Il ne s'agit pas d'un manque de ressources, mais d'une **violation d'accès**.
* **Erreur :** Segmentation Fault (SIGSEGV).
* **Explication :** Le programme tente d'écrire (`Invalid write`) à l'adresse **0x0 (NULL)**. 
* **Mécanisme :** L'adresse 0 est réservée au Kernel. Le CPU bloque l'instruction par sécurité, peu importe la quantité de RAM disponible.



---

##  4. Aliasing Analysis (`aliasing_example.c`)

> **Analyse de l'IA :** > "Ayant aucun `free(b)`, le pointeur `b` est encore valide après `free(a)`."

### La bonne analyse
C'est une erreur de logique sur la nature des pointeurs.
* **Erreur :** Use-after-free (détecté par le compilateur via `-Werror=use-after-free`).
* **Explication :** `a` et `b` sont des **alias** : ils stockent la même adresse mémoire. 
* **Conséquence :** `free` libère le *contenu* de l'adresse, pas le nom de la variable. Une fois la mémoire libérée via `a`, le pointeur `b` devient un **Dangling Pointer** (suspendu) pointant vers une zone désormais invalide.