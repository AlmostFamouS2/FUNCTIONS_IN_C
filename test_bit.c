#include <stdio.h>
#include <math.h>

//Created By Vitor Gusmao
int main(void){
	unsigned long int num;
	unsigned long int bit=1;
	printf("Digite o numero a seguir---> ");
	scanf("%lu",&num);
	while(pow(2,bit)<num+1){bit+=1;}
	printf("The number needs only %ld bits\n",bit);
	return 0;
} 
