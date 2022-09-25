#include <stdio.h>
#include <stdlib.h>

int slen(char *s){
        int i = 0;

        while (*s++)
                i++;
        return i;
}

void *ft_atoi(char *string){

        int len = slen(string);
        int *result = (int*)malloc(sizeof(int)*slen(string));
        *result = 0;
        long long int exp = 1;

        char *ptr = string;
        ptr += len-1;

        while (ptr >= string){
                *result += ((*ptr)-0x30) * exp;
                exp *= 10;
                ptr--;
        }

        return result;
}

int main(int argc, char *argv[]){
        if (argc == 1)
                return -1;

        int *num = ft_atoi(argv[1]);
        printf("%d\n", (*num) * (*num));

return 0;
}
