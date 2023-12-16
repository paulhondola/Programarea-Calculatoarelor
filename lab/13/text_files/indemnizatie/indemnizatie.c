/*
Se consideră un fișier csv (comma separated values) în care pe fiecare linie se află mai multe câmpuri separate prin semnul punct-virgulă. Fișierul conține informații statistice oferite de Institutul National de Statistica prin platforma OpenData a Guvernului Romaniei (https://data.gov.ro/) despre plata indemnizațiilor de creșterea copilului pe o anumită lună din anul 2021. Fișierul are următorul cap de tabel ce descrie câmpurile din liniile conținue
Judet;Populatie;Beneficiari plãtiti;Beneficiari suspendati la sfârsit de lunã;Suma totalã plãtitã drepturi curente;Alte plãþi
Programul va citi acest fișier folosind funcțiile dedicate pentru citirea fișierelor text, va extrage câmpurile judet, beneficiari platiti si suma total platita drepturi curente, si va stoca datele într-un tablou alocat dinamic, de structuri de date corespunzătoare, de dimensiune minimă necesară. Se cere să se implementeze tipuri de date utilizator. Se va implementa de asemenea o funcție de sortate dupa judet și o funcție de sortare după suma totala platita drepturi curente. Programul va scrie în fișierul rezultat.txt pe câte un rând diferit judetul cu cea mai mare populatie, judetul cu cea mai mare suma din câmpul alte plati.

Fișierul se poate descărca folosind următoarea comandă:

wget http://staff.cs.upt.ro/~valy/pt/indemnizatie.csv
*/