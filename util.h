#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


// ============== SORT ===================>
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
// =========== REVERSE_SORT =============>
void rsort(int arr[], int len){
        int k, val;

        for(int i = 1; i < len; i++){
                val = arr[i];
                for( k = i-1; k >= 0 && val > arr[k]; k--)
                        arr[k+1] = arr[k];

                arr[k+1] = val;
        }
}
// ------------- BinS ------------------->

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

// -------------_ STELEN -------------------->
int _strlen(char *vs){
	int n = 0;
	for(int i = 0; vs[i] ; i++){
		if(vs[i] == ' ')
			continue;
		n++;
	}
return n;

}
// -------------- ILEN -> INTEGER LENGHT ----------------------------->
int ilen(int li[]){
	int n = 0;
	while(li[n])
		n+=4;
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
// --------------- MAX -------------------------->
int max(int a, int b){
	return a*(a>b) + b*(b>=a);
}
// --------------- MIN ------------------------->
int min(int a, int b){
	return a*(a<b) + b*(b<=a);
}
// -------------  _STRCPY ------------------------>
void _strcpy(char *v1, char *v2)
{
	while ( *v1++ = *v2++ );
}
// ------------------------------------------------>
int _strcmp(char *a, char *b){
	if(_strlen(a) != _strlen(b))
		return 0;

	for(int i = 0; i < _strlen(a); i++)
		if(a[i] != b[i])
			return 0;

	return 1;
}
// ----------------- TO_LOWER ---------------------->
char *to_lower(char* str){
    for(int i=0; str[i] != '\0'; i++){
        if(str[i] >= 65 && str[i] <=90)
           str[i] += 32;
        }
    return str;
}

// ---------------- STRSRCH ---------------------->
int strsrch(char *str, char s){
	int i;  // ITERATOR

	for (i = 0; str[i] ; i++)
		if (str[i] ==  s)
			break;
    return i;
}
// --------------- FILE_CP ----------------------->
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
// ---------------- ATOI ------------------->
long long int ft_atoi(char *string){
        for(int i = 0; i < _strlen(string); i++)
                if ((string[i] < 0x30 || string[i] > 0x39) && string[0] != '-'){ //string[0]!='-' 'cause it can be negative.
                        fputs("\x1b[31m O NUMERO DIGITADO NAO EH VALIDO!\x1b[0m\n\n", stderr);
                        return -1;
                }

        int len = _strlen(string);
        register long long int result = 0;
        long long int exp = 1;

        char *ptr = string;
        ptr += len-1;

        while (ptr >= string && *ptr != '-'){
                result += ((*ptr)-0x30) * exp;
                exp *= 10;
                ptr--;
        }

        return (string[0]=='-') ? -result : result;
}
// ---------------- DEC2BIN ------------------->
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
// --------------  _ATOI  -------------------->

int _atoi(char *argv){
	short *c = (short *) argv;
	return *c - 0x30;
}

// ---------------STARTSWITH-------------------------->

short startswith(char chr, char *vec){
	return (vec[0] == chr);
}

// -----------------ENDSWITH-------------------------->

int endswith(char str, char p[]){
	return (p[_strlen(p) - 1] == str);
}

// ------------- quicksort in C --------------------------->
void qsort(int a[], int lo, int hi){
    int h, l, p, t;
	
    if (lo < hi) {
    	l = lo;
	h = hi;
	p = a[hi];
	    
	do {
	    while ((l < h) && (a[l] <= p))
		   l+=1;
	    while ((h > l) && (a[h] >= p))
		   h -= 1;
	if (l < h) {
	    t = a[l];
	    a[l] = a[h];
	    a[h] = t;
	}
	} while (l < h);
	    
	a[hi] = a[l];
	a[l] = p;
	    
	qsort(a, lo, l-1);
	qsort(a, l+1, hi);
    }
}
// ------------- _memcpy--------------------------->
#if defined __x86_64__
#define MEM 8
#elif __i386__
#define MEM 4
#endif

void _memcpy(char *s, char *t, int8_t size){
	char *p = s, *q = t;

size += MEM; // IDK why but... this works only with it
	while( size-- )
		*p++ = *q++;
}
