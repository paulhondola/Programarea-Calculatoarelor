# ETAPELE COMPILARII

- fisier cod sursa (.c)
- preprocesor (directiva `#include`)
- compilator (traduce codul sursa in cod obiect)
- asamblor (traduce codul obiect in cod masina)
- linker sau link editor (genereaza executabilul)
- executabil (fisier binar)

flagurile de debug apar in codul obiect (object file)



- MAKEFILE / CMAKE
  
- `gcc -o hello hello.c` (compilare si linkare)
- `gcc -c hello.c` (compilare)
- `gcc -Wall -o hello hello.c` (compilare si linkare cu flaguri de warning)




### TRATAREA ERORILOR

- compilare
- link-editare
- warning


# FISIERE HEADER

`int functie(int a, int b);` - declararea functiei (antetul)

```
int functie() 
{
    ceva
}
``` 
- definirea functiei (corpul)

- definirea - tip de data, nume, memorie

- declararea - tip de data, nume

extern int a; - declarare variabila globala
int a; - definire variabila

>### fisierele .h contin doar declarari - variabile cu extern, functii


- fisierele .c se compileaza , nu se includ
- fisierele .h se includ, nu se compileaza



> # HEADER STRUCTURE

- include guards - blocheaza includerea de mai multe ori a aceluiasi fisier header

> \#ifndef __HEADER_H
> 
> \#define __HEADER_H
>
> typedef struct{
> } data
>
> 
>
> \#endif