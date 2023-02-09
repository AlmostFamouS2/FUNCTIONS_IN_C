#include <stdio.h>
#include <string.h>

char cript(char letter){
	if((letter > 87 && letter < 91) || (letter < 123 && letter > 119))
	{
		return letter-=23;
	}
	return letter+3;
}

int main(int argc, char *argv[]){

for(short v=1;v<argc;v++){
	short len=strlen(argv[v]);

for(short i=0;i<len;i++)
{
	printf("%c ", cript(argv[v][i]));
}
printf(" ");
}
puts("");
return 0;
}