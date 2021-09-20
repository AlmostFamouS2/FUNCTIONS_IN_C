#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>

typedef struct {
    char name[4];
    float v;
} re;

void cp(float *s1, float *s2)
{
	while( *s1++ = *s2++);
}

/*  NEM PRECISEI DE USAR.
int find_index(float *s1, float k)
{
	int i = 0;

	for(i ; s1[i] != k && i < strlen(s1); i++);
	return i;
}
*/

float *float_sort(float ss[], int len){
	float *s = (float*) malloc(sizeof(float) * len);

	cp(s, ss);

	int val, k;

	for(int i = 1; i < len; i++)
	{
		val = s[i];
		for( k = i-1; k >= 0 && s[k] > val; k--)
			s[k+1] = s[k];

		s[k+1] = val;		
	}

	return s;
}

int main(){
	int sum = 0, i = 0;
	float results[4] = {0};
	char msgs[4][4] = {"M-F", "F-F", "F-M", "M-M"};
	int n;

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
float *s = float_sort(results, sizeof(results)/sizeof(float));    // EU REALMENTE NAO ACREDITO QUE CONSEGUI FAZER ISSO

re hahaha[4];
    memcpy(hahaha[0].name, "M-M", 4);
    hahaha[0].v = results[0];

    memcpy(hahaha[1].name, "F-F", 4);
    hahaha[1].v = results[1];

    memcpy(hahaha[2].name, "F-M", 4);
    hahaha[2].v = results[2];

    memcpy(hahaha[3].name, "M-F", 4);
    hahaha[3].v = results[3];
    

printf("\x1b[33m---------------------------------------------------------------------------\n");

      for(int j = 0; j < s[3]/3; j++){
    	  if(hahaha[0].v > 0)
	       printf("   ###");

	    if (hahaha[1].v > 0)
		    printf("      ###");

	    if (hahaha[2].v > 0)
		    printf("         ###");

	    if (hahaha[3].v > 0)
		    printf("            ###");
	    puts("|");

    for(int i = 0; i < 4; i++)
	    hahaha[i].v -= 3;
}

printf("   ");
for(int i = 0; i < sizeof(msgs)/sizeof(msgs[0]); i++)
	printf("%s   ", hahaha[i].name);
putchar('\n');

printf("\x1b[0m");

free(s);
return 0;
}
