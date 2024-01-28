/*
Intr-un fișier se scriu datele când concurenții termina o cursa. În alt fișier se afișează pe prima linie timpul cel mai rapid în care cineva termina cursa, iar pe restul liniilor diferența de timp. (nu mai știu sigur dacă în exemplul dat la test componentele din timp se luau cu 0 în față dacă erau mai mici decat 10 sau nu) 
Ex : 
fișier.in 
    04:05:31
    03:02:01
    10:18:43
fișier.out 
    03:02:01
+  01:03:30
+  07:16:42
*/

// 04:05:31 - 03:02:01 = 01:03:30
// 10:18:43 - 03:02:01 = 07:16:42

#include "header.h"

int main(void)
{
    FILE *input = open_file("cronometru.in", "r");
    FILE *output = open_file("cronometru.out", "w");

    uint32_t size = 0;
    TIME_T *times = read_all_times(input, &size);

    sort_all_times(times, size);

    write_all_times(output, times, size);
    
    write_all_differences(output, times, size);

    close_file(input);
    close_file(output);

    return 0;
}
