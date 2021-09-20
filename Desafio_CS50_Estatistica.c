#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>

int main(){
	int sum = 0, i = 0;
	float results[4] = {0};
	char msgs[4][8];
	int n;

	memcpy(msgs[0], "M---->F", 7);
	memcpy(msgs[1], "F---->M", 7);
	memcpy(msgs[2], "F---->F", 7);
	memcpy(msgs[3], "M---->M", 7);

      struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

	while(sum != 10 || i != 4){
		if(i >= 4){
		    puts("\x1b[31mNAO FOI EXATAMENTE 10 no total da soma!\n Reinicializando...\x1b[0m");
		    i = 0;}
		sum = 0;

		puts("\n\n INICIZALIZANDO...");

		printf("M procurando F: ");
		scanf("%d", &n);
		sum += n;  i++;
		results[0] = w.ws_col * ((float)n/10);

		printf("F procurando M: ");
		scanf("%d", &n);
		sum += n;   i++;
		results[1] = w.ws_col * ((float)n/10);


		printf("F procurando F: ");
		scanf("%d", &n);
		sum += n; i++;
		results[2] = w.ws_col * ((float)n/10);


		printf("M procurando M: ");
		scanf("%d", &n);
		putchar('\n');
		sum += n;  i++;
		results[3] = w.ws_col * ((float)n/10);
	}

// --------------------------------------------------------
printf("\x1b[33m");
    for(int i = 0; i < 4; i++){
	    printf("%s ======= %.2f\n", msgs[i], results[i]);
	   for(int j = 0; j < results[i]; j++){
		   putchar('#');
	   	}
	   puts("\n");
	}
printf("\x1b[0m");
return 0;
}
