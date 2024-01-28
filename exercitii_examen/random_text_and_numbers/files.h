#ifndef __FILES_H__
#define __FILES_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE *open_file(char *filename, char *mode);

void close_file(FILE *file);

#endif
