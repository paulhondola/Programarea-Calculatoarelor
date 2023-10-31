#include <stdio.h>
#include <stdint.h>

int adunare(int a, int b)
{
	int r;
	r = a + b;
	return r;
}

void bim(void)
{
	printf("bimbimbambam\n");
	return;
}

int main(void)
{

	/*
	
	*/

	// operatorul ternar
	// rez = (expresie) ? valoare_true : valoare_false;
	/*
	echivalent cu

	if(expresie)
	{
		rez = valoare_true;
	}
	else
	{
		rez = valoare_false;
	}
	*/

	int rez = (1 < 3)? 7 : 15;

	printf("%d\n", rez);

	/*

	switch - case

	!!! fara float / double in switch la case

	switch(expresie)
	{
		case valoare1:
		{
			secv1;
			break;
		}
		case valoare2:
		{
			secv2;
			break;
		}
		default:
			secv_default;
	}

	*/
	
	/*

	!!! ciclu cu test initial

	while(expresie)
	{
		instructiune;
	}

	!!! ciclu cu test final

	do
	{
		instructiune;
	} while(expresie);

	!!! for

	for(expr1; expr2; expr3)
	{
		instructiuni;
	}

	expr1 - se evalueaza la inceput, o singura data
	expr2 - se eval., daca este true, se ruleaza instructiunile
	expr3 - se executa la finalul rularii instructiunilor


	int i = 0;
	for(; i < 10; i++, k--, n = n + k....... )
	{
	
	}
	
	*/


	/*
	
	continue si break - pt bucle

	break - sparge prima bucla din care face parte

	continue - sparge iteratia curenta, se sare la urmatoarea iteratie

	*/

	/*

	!!! functii

	tip_rezultat nume_functie(declaratie de parametri)
	{
		declaratii variabile;
		lista_instructiuni;
		return valoare;
	}

	*/

	printf("%d\n", adunare(1, 1));
	bim();



	/*

	ZONE DE MEMORIE !!! - adresa creste de la segm de cod la date dupa la heap si stack

	- se executa in RAM - procesul de runtime

	la baza - segment de cod
	Read Only - .code sau .txt



	Read - Write (variabile) - fixe ca structura si dimensiune in runtime

	b) zona de date initializate .data - date globale init

	a) date neinitializate .bss - date globale neinit

	
	
	Heap ------------------- Stack

	heap - limitate doar de memoria sistemului
	stack - limitata de sistemul de operare ~ 8 gb

	heap si stiva nu se suprascriu

	cu stiva - apel de functii




	Stiva - LIFO - last in first out

	push - pui peste  stiva
	pop - remove la ultimul element
	doar ultimul il poti modifica


	STACK FRAME

	new stack pointer
	variabila m
	...........
	variabila 1
	arg n - 1
	arg n - 2
	...........
	arg 1
	arg 0
	return value
	return address
	current stack pointer


	

	Reserved - argumente in linie de comanda / variabile de mediu


	int a; - bss
	int b = 5; - data

	int main()
	{
	int n; - stack
	static int x; - bss
	static int y = 5; - data
	}
	static int n = 0; - muta variabila locala de pe stiva in zona de date
	
	pt optimizare a spatiului si a timpului

	cu static pot modifica variabile din functii

	*/
	
	
	static int tab[4000000];
	
	
	

	
	return 0;
}