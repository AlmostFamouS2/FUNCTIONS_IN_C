#include <stdio.h>

int main(){
	FILE *fp, *fn;
	unsigned char bytes[60];

	fp = fopen("binary.txt", "rb");   // escrita para binarios
	fn = fopen("content", "wb");      // escrita para binarios

	if (fp == NULL){
		puts("ERRO AO ABRIR O ARQUIVO ORIGINAL!");
		return 1;
	}

	fread(bytes, sizeof(unsigned char), 60, fp);
	fwrite(bytes, sizeof(unsigned char), 60, fn);

	for(int i = 0; i < 60; i++){
		printf("%X ", bytes[i]);
	}

	fclose(fp);
	fclose(fn);
return 0;
}
