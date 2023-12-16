/*
Un fisier binar incepe cu un numar fara semn pe 32 de biti care reprezinta numarul de inregistrari din fisier. Dupa acesta urmeaza inregistrarile, implementate prin structura urmatoare:
- an - nr fara semn pe 16 biti
- luna - nr fara semn pe 8 biti
- zi - nr fara semn pe 8 biti
- idx senzor - nr fara semn pe 8 biti
- valoare - nr cu semn pe 16 biti
O inregistrare codifica valoarea citita de un senzor la o anumita data. Valorile corecte pot fi in intervalul [-1000,1000]. Daca un senzor da din cand in cand valori in afara intervalului, atunci se considera ca are probleme. Daca toate valorile sunt in afara intervalului, atunci senzorul este defect.
Cerinte:
- sa se scrie o functie care creaza un fisier de test, ce cuprinde valori pentru un senzor care merge, altul care are probleme
si altul defect.
- sa se citeasca fisierul de test si sa se afiseze care senzor merge, care are probleme si care e defect.
- se cere de la tastatura un an si o luna. Se cere sa se afiseze toate valorile senzorilor din acel an/luna.
*/