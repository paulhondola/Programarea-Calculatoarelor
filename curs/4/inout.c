#include <stdio.h>
#include <ctype.h>
int main(void)
{
	// ctrl + C - eof pe macos


	/*
	int ch;
	while((ch = getchar()) != EOF)
	{
		putchar(ch);
	}

	printf("Gata\n");
	*/

	// ./exe < test.txt - citire din fisier
	// ./exe > test.txt - scriere in fisier

	// wc < input.in - word count - newline, cuvinte, 13 bytes


	int line_count = 0, word_count = 0, byte_count = 0;
	printf("%d %d %d\n", line_count, word_count, byte_count);

	int ch;
	int prev_ch;
	while((ch = getchar()) != EOF)
	{
		byte_count++;
		if (ch == '\n')
		{
			line_count++;

		}
		if (isspace(ch) && !isspace(prev_ch))
			word_count++;

		prev_ch = ch;
	}

	return 0;
}