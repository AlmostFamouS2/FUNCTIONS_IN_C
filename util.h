#include <stdio.h>
#include <stdlib.h>


// =========== SORT FUNCION ====================>
void sort(int v[], int size)
{
	int val, k;

	for(int i=1; i < size; i++){
		val = v[i];

		for(k = i-1; k >= 0 && v[k] > val; k--)
			v[k+1] = v[k];

		v[k+1] = val;
	}
}
// ---------- BINARY SEARCH --------------------->

int BinS(int v[], int size, int n)
{
	int inf = 0, sup=size-1, middle;

	while(inf <= sup){
		middle = (sup+inf)/2;

		if(v[middle] < n)
			inf = middle+1;
		else if(v[middle] > n)
			sup = middle-1;
		else
			return middle;
	}
return 0;
}

// -------------- STRLEN FUNC --------------------->
int _strlen(char *vs){
	int n = 0;
	for(int i = 0; vs[i] ; i++){
		if(vs[i] == ' ')
			continue;
		n++;
	}
return n;

}
/*
int _strlen(char *str){

    int i = 0;
       while(str[i] != '\0')
		   i++;
return i;
}
*/
// --------------  MAXIMUM ----------------------->
int max(int a, int b){
	return a*(a>b) + b*(b>=a);
}
// -------------- MINIMUM  ----------------------->
int min(int a, int b){
	return a*(a<b) + b*(b<=a);
}
// ----------STRING COPY ------------------------->
void _strcpy(char *v1, char *v2)
{
	while ( *v1++ = *v2++ );
}
// ------------------------------------------------>
/*  // I haven't ended up this

void sec_copy(char *dest, char *begin)
{
		if(_strlen(begin) > _strlen(dest)){
			fprintf(stderr, "NOT POSSIBLE TO COPY STRING GREATER THAN ANOTHER IN STACK!\n");
			exit(1);
		}
	while ( *dest++ = *begin++ );
}
*/
// ----------- STRING COMPARE ---------------------->
int _strcmp(char *a, char *b){
	if(_strlen(a) != _strlen(b))
		return 0;

	for(int i = 0; i < _strlen(a); i++)
		if(a[i] != b[i])
			return 0;

	return 1;
}
// -----------TO LOWERCASE ------------------------->
char *to_lower(char* str){
    for(int i=0; str[i] != '\0'; i++){
        if(str[i] >= 65 && str[i] <=90)
           str[i] += 32;
        }
    return str;
}

// ------------STRING SEARCH ---------------------->
int strsrch(char *str, char s){
	int i;  // ITERATOR

	for (i = 0; str[i] ; i++)
		if (str[i] ==  s)
			break;
    return i;
}
// ------------------------------------------------>
void file_cp(char *file1, char *file2)
{
	FILE *fin;
	FILE *fout;
	unsigned char c;

	fin = fopen(file1, "rb");
	fout = fopen(file2, "wb");

	while(fread(&c, sizeof(c), 1, fin))
		fwrite(&c, sizeof(c), 1, fout);

	fclose(fin);
	fclose(fout);
}
// -------- DECIMAL TO BINARY ----------------------->
void dec2bin(int num){

	int c[16] = {0}, count = 0;
	
	while (num != 0){
		c[count] = num%2;
		num /= 2;
	count++;
	}

  for(int i = (sizeof(c)/4)-1; i >= 0; i--)
	printf("%d",c[i]);
puts("");
}
// --------------  _ATOI NATIVA   -------------------->

int _atoi(char *argv){
	short *c = (short *) argv;
	return *c - 0x30;
}

// ------------   STARTSWITH   --------------------->

short startswith(char chr, char *vec){
	return (vec[0] == chr);
}


/*int startswith(char chr, char *vec){
	(vec[0] == chr) ? 1 : 0;
}
*/
// ------------ ENDSWITH -------------------------->

int endswith(char str, char p[]){
	return (p[_strlen(p) - 1] == str);
}


/*
short endswith(char str, char *p){
	if( p[_strlen(p)] == str){
		return 1;
	} else {
		return 0;
	}
} */

// -------------------------------------------------->
