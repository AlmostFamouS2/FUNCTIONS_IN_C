#include <stdio.h>
#include <stdlib.h>

int slen(char *s){
        int i = 0;

        while (*s++)
                i++;
        return i;
}

long long int ft_atoi(char *string){
        for(int i = 0; i < slen(string); i++)
                if ((string[i] < 0x30 || string[i] > 0x39) && string[0] != '-'){ //string[0]!='-' 'cause it can be negative.
                        fputs("\x1b[31m O NUMERO DIGITADO NAO EH VALIDO!\x1b[0m\n\n", stderr);
                        return -1;
                }

        int len = slen(string);
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

int main(int argc, char *argv[]){
        if (argc == 1)
                return -1;

        register unsigned int num = ft_atoi(argv[1]);
        if (num == -1){
                puts("INFELIZMENTE, SEU PROGRAMA NAO RODARA!");
                return 1;
        }
        printf("%lu\n", num * num);

return 0;
}
