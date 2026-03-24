## 1. Heap Analysis (heap_example.c)
**Memory State (Post-Allocation)**
***Stack (Pile) :*** Contient la variable locale p (8 octets sur 64-bit), qui stocke l'adresse mémoire du bloc Person sur le Heap.

***Heap (Tas) :*** * Bloc A : Structure Person (contient l'âge et un pointeur name).

***Bloc B :*** Chaîne de caractères "Alice" (6 octets).

**Lien :** p->name est un pointeur qui "pointe" du Bloc A vers le Bloc B.

**Critique de l'IA**
>Erreur IA : L'IA a affirmé que free(p) était suffisant car "le programme libère la structure allouée".

>Ma Correction : C'est une erreur de Shallow Free. L'IA ignore la hiérarchie mémoire. Libérer p détruit le Bloc A, mais le Bloc B ("Alice") reste alloué sans que personne n'ait plus son adresse. C'est une fuite de mémoire (Memory Leak) par perte de propriété (lost ownership).

## 2. Stack Analysis (stack_example.c)
**Memory State (Function Scope)**
Stack Frame (get_string) : Contient le tableau str[10] initialisé avec "Hello".

Lifetime (Durée de vie) : La variable str a une durée de vie automatique. Elle est détruite dès que l'exécution atteint le return.

État Post-Return : Le pointeur récupéré dans le main est un Dangling Pointer. Il pointe vers une zone de la pile qui est désormais "libre" pour être réutilisée par une autre fonction.

**Critique de l'IA**
>Erreur IA : L'IA a prétendu que le code était "sûr" car il s'exécute sans erreur Valgrind.

>Ma Correction : L'IA confond succès d'exécution et validité mémoire. Le fait que "Hello" s'affiche est une coïncidence (la zone mémoire n'a pas encore été écrasée). C'est un Undefined Behavior critique que l'IA n'a pas su détecter.

## 3. Aliasing Analysis (aliasing_example.c)
**Memory State (Pointer Copy)**
***Stack :*** Deux variables distinctes, a et b.

Heap : Un seul bloc de 10 octets alloué via malloc.

***Aliasing :*** Après l'instruction b = a, les deux variables stockent la même adresse. Elles sont des alias du même objet physique.

**Critique de l'IA**
>Erreur IA : L'IA a suggéré que b restait valide après free(a) car "on n'a pas libéré b".

>Ma Correction : L'IA ne comprend pas la différence entre le pointeur (le nom) et la donnée (l'adresse). free libère la zone mémoire à l'adresse donnée. Une fois la zone libérée via a, le pointeur b devient invalide. L'utiliser provoque un Use-after-free.

---

## 4. Crash Analysis (crash_example.c)
**Memory State (Invalid Access)**
***Stack : Variable p initialisée à 0x0 (NULL).***

***Virtual Address Space :*** L'adresse 0 n'appartient à aucun segment de mémoire (ni Pile, ni Tas, ni Data). Elle est protégée par le système d'exploitation.

**Critique de l'IA**
>Erreur IA : L'IA a émis l'hypothèse d'un manque de mémoire RAM pour expliquer le crash.

>Ma Correction : Diagnostic totalement hors-sujet. Un Segmentation Fault sur un pointeur NULL est un événement déterministe lié aux droits d'accès. Peu importe la RAM disponible, le MMU (Memory Management Unit) bloquera toujours l'accès à l'adresse 0x0.

---