#include <stdio.h>
#include <string.h>

void menu(void)
{
	printf("\n1) Decimal to binary\n");
	printf("2) Decimal to hex\n");
	printf("3) Binary to decimal\n");
	printf("4) Binary to hex\n");
	printf("5) Hex to decimal\n");
	printf("6) Hex to binary\n");
	printf("0) Quit\n\n");
}


int bin_to_dec(char *bin)
{
	int dec = 0, pow = 1;

	for(int i = strlen(bin) - 1; i >= 0; i--)
	{
		if(bin[i] == '1')
			dec += pow;
		pow *= 2;
	}

	return dec;
}


char *hex_to_bin(char *hex)
{
	static char bin[256] = "\0";
	strcpy(bin, "\0");
	for(int i = 0; i < strlen(hex); i++)
	{
		switch(hex[i])
		{
			case '0':
				strcat(bin, "0000");
				break;
			case '1':
				strcat(bin, "0001");
				break;
			case '2':
				strcat(bin, "0010");
				break;
			case '3':
				strcat(bin, "0011");
				break;
			case '4':
				strcat(bin, "0100");
				break;
			case '5':
				strcat(bin, "0101");
				break;
			case '6':
				strcat(bin, "0110");
				break;
			case '7':
				strcat(bin, "0111");
				break;
			case '8':
				strcat(bin, "1000");
				break;
			case '9':
				strcat(bin, "1001");
				break;
			case 'a':
			case 'A':
				strcat(bin, "1010");
				break;
			case 'b':
			case 'B':
				strcat(bin, "1011");
				break;
			case 'c':
			case 'C':
				strcat(bin, "1100");
				break;
			case 'd':
			case 'D':
				strcat(bin, "1101");
				break;
			case 'e':
			case 'E':
				strcat(bin, "1110");
				break;
			case 'f':
			case 'F':
				strcat(bin, "1111");
				break;
		}
	}
	strcat(bin, "\0");
	return bin;
}


char *dec_to_bin(int dec)
{
	static char bin[256] = "";
	int len = 0;
	
	while(dec)
	{
		if(dec % 2)
			bin[len++] = '1';
		else
			bin[len++] = '0';
		dec /= 2;
	}
	bin[len] = '\0';

	for(int i = 0; i < len / 2; i++)
	{
		char aux = bin[len - 1 - i];
		bin[len - 1 - i] = bin[i];
		bin[i] = aux;
	}

	char *ptr = bin;
	return ptr;
}


char *bin_to_hex(char *bin)
{
	static char hex[256] = "";
    strcpy(hex, "\0");
	int len = 0;

	if(strlen(bin) % 4)
	{
		char aux[256] = "";
        int i;
		for(i = 0; i < 4 - strlen(bin) % 4; i++)
			aux[i] = '0';
        aux[i]='\0';

		strcat(aux, bin);
		strcpy(bin, aux);
	}

	for(int i = 0; i < strlen(bin); i+=4)
	{
		int result = 0;
		for(int j = i; j < i + 4; j++)
			result = 10 * result + (bin[j] - '0');

		switch (result)
		{
		case 0:
			hex[len++] = '0';
			break;
		case 1:
			hex[len++] = '1';
			break;
		case 10:
			hex[len++] = '2';
			break;
		case 11:
			hex[len++] = '3';
			break;
		case 100:
			hex[len++] = '4';
			break;
		case 101:
			hex[len++] = '5';
			break;
		case 110:
			hex[len++] = '6';
			break;
		case 111:
			hex[len++] = '7';
			break;
		case 1000:
			hex[len++] = '8';
			break;
		case 1001:
			hex[len++] = '9';
			break;
		case 1010:
			hex[len++] = 'A';
			break;
		case 1011:
			hex[len++] = 'B';
			break;
		case 1100:
			hex[len++] = 'C';
			break;
		case 1101:
			hex[len++] = 'D';
			break;
		case 1110:
			hex[len++] = 'E';
			break;
		case 1111:
			hex[len++] = 'F';
			break;
		default:
			break;
		}
		
	}
	hex[len] = '\0';
		
	return hex;
}


char *dec_to_hex(int dec)
{
	char *bin = dec_to_bin(dec);
    char *hex = bin_to_hex(bin);
    return hex;
}


int hex_to_dec(char *hex)
{
	char *bin = hex_to_bin(hex);
	int dec = bin_to_dec(bin);
	return dec;
}


int main(void)
{
	int opt = 0;
	int dec = 0;
	char bin[] = "";
	char hex[] = "";

	do
    {
		menu();

		scanf("%d", &opt);

		switch(opt)
		{
		case 1:
			printf("Input a decimal number:\n");
			scanf("%d", &dec);
			printf("The binary number is:\n0b%s\n", dec_to_bin(dec));
			break;
		case 2:
			printf("Input a decimal number:\n");
			scanf("%d", &dec);
			printf("The hexadecimal number is:\n0x%s\n", dec_to_hex(dec));
			break;
		case 3:
			printf("Input a binary number:\n0b");
			scanf("%s", bin);
			printf("The decimal number is:\n%d\n", bin_to_dec(bin));
			break;
		case 4:
			printf("Input a binary number:\n0b");
			scanf("%s", bin);
			printf("The hexadecimal number is:\n0x%s\n", bin_to_hex(bin));
			break;
		case 5:
			printf("Input a hexadecimal number:\n0x");
			scanf("%s", hex);
			printf("The decimal number is:\n%d\n", hex_to_dec(hex));
			break;
		case 6:	
			printf("Input a hexadecimal number:\n0x");
			scanf("%s", hex);
			printf("The binary number is:\n0b%s\n", hex_to_bin(hex));
			break;
		default:
			break;
		}
		
	} while(opt);

	return 0;
}
