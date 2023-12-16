/*
Se consideră un fișier text ce conține un număr necunoscut de linii de text de o dimensiune necunoscută. Să se scrie un program ce citește un astfel de fișier și stochează datele într-un tablou alocat dinamic de string-uri C alocate dinamic. Se va folosi o amprentă minimă de memorie. Se vor scrie de asemenea și următoarele funcții
o funcție void write_sort(char **lines, char *filepath); - funcția va prelua tabloul de linii, le va sorta alfabetic și le va scrie în fișierul cu calea filepath. Se va realiza conex și o funcție de sortare a tabloului de linii lines. Se poate folosi bubble-sort. Pentru compararea aflabetică a două linii se poate folosi funcția strcmp(...)
o funcție void write_random(char **lines, char *filepath); - funcția va prelua tabloul de linii și le va scrie în fișierul referit prin calea filepath în ordine aleatoare a liniilor. Hint ! Se poate folosi funcția rand(....);
o funcție uint32_t find_word(char **lines, char *word); - funcția va căuta cuvântul referit prin word în tabloul de linii lines și va returna numărul de apariții.
Fișierul de test se poate descărca folosind următoarea comandă:

wget http://staff.cs.upt.ro/~valy/pt/scrisoare.txt
*/