#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	int num = 7;

	if(argc == 1)
		puts("\x1b[33m UTILIZANDO O PADRAO DE 7 CAMADAS.\x1b[0m");
	else
		num = atol(argv[1]);

	if(num == 0){
	    fprintf(stderr, "\x1b[31m NUMERO INVALIDO! Apenas numeros aqui.\n\x1b[0m");
	    return 1;
	}

	for(int i = 0; i <= (num >> 1) + 1; i++){
		for(int j = 0; j < num; j++)
			if(j >= (i) && j < (num-i))
				printf("  *");
			else
				printf("   ");

		putchar('\n');
	}

    return 0;
}
