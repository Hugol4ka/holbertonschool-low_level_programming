### 1. Analyse du Heap (heap_example.c)
**Problème :** Fuite de mémoire (Memory Leak) par perte de propriété (Lost Ownership).

***Diagnostic Valgrind :*** definitely lost: 6 bytes in 1 blocks.

***Analyse de l'IA :*** L'IA affirme souvent que le code est correct car elle voit un free(p). Elle conclut qu'il n'y a pas de fuite.

***La Réalité Technique :*** C'est un Shallow Free (libération superficielle). La structure Person contient un pointeur name vers une chaîne allouée dynamiquement ("Alice"). En libérant la structure p sans libérer d'abord p->name, l'adresse de la chaîne est perdue à jamais.

>Ma Critique : L'IA échoue car elle ne suit pas la chaîne de dépendance des allocations. Elle ignore que chaque malloc interne nécessite son propre free.

### 2. Analyse de la Stack (stack_example.c)
**Problème :** Violation de durée de vie (Lifetime Violation) et Pointeur Suspendu (Dangling Pointer).

***Diagnostic Valgrind :*** ERROR SUMMARY: 0 errors.

***Analyse de l'IA :*** "Le rapport affiche 0 erreur, donc le programme est sûr."

***La Réalité Technique :*** C'est un Faux Négatif de Valgrind. Le programme retourne l'adresse d'une variable locale (str) après la fin de la fonction. Cette zone de la Stack Frame est invalidée dès le return.

>Ma Critique : Se fier uniquement à Valgrind est dangereux. L'IA ignore que le succès de l'affichage (le fait qu'on lise encore "Hello") est une coïncidence : la mémoire n'a simplement pas encore été écrasée par une autre fonction. C'est un Undefined Behavior.

### 3. Analyse du Crash (crash_example.c)
**Problème :** Déréférencement de pointeur nul (NULL Dereference).

***Diagnostic Valgrind :*** Invalid write of size 4 à l'adresse 0x0.

***Analyse de l'IA :*** "Le programme manque de RAM ou la pile est trop petite."

***La Réalité Technique :*** C'est une erreur de logique, pas de ressources. Le pointeur vaut 0x0. L'unité de gestion de la mémoire (MMU) bloque l'accès car l'adresse 0 est réservée au Kernel. Le système envoie un signal SIGSEGV pour protéger l'intégrité logicielle.

>Ma Critique : L'IA propose une solution matérielle (plus de RAM) à un problème logiciel. Même avec une mémoire infinie, l'accès à l'adresse 0 provoquera toujours un crash déterministe.

### 4. Analyse de l'Aliasing (aliasing_example.c)
Problème : Utilisation après libération (Use-after-free).

***Diagnostic :*** Bloqué à la compilation (-Werror=use-after-free).

***Analyse de l'IA :*** "Comme on n'a pas fait free(b), le pointeur b est encore valide."

***La Réalité Technique :*** a et b sont des alias : ils pointent vers le même bloc sur le Heap. Faire free(a) détruit la donnée vers laquelle b pointe aussi. b devient instantanément un Dangling Pointer.

>Ma Critique : L'IA confond la variable (le nom) et la zone mémoire (l'adresse). Elle ne comprend pas que libérer l'un, c'est invalider l'autre.