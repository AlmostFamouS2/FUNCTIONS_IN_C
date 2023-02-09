#include <stdio.h>

int main(int argc, char *argv[]){
	int n;

	if(argc > 1 && atoi(argv[1]) < 50)
		n = atoi(argv[1]);
	else
		n = 9;


	for(int i = 0; i <= n; i++) {
		for(int j = 1; j <= (n << 1) - 1; j++)
			if( j >= n-(i-1) && j <= (n+i)-1)
				printf("*");
			else
				printf(" ");
	puts(" ");
	}

return 0;
}
