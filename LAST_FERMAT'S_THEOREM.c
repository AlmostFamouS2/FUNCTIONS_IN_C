#include <stdio.h>
#define UINT unsigned int

/*
 O famoso "Último Teorema de Fermat" afirma que não há solução para a equação x^n+y^n=z^n, se n for um inteiro maior do que 2 e (x,y,z) naturais (inteiros >0)
 */

int fermat_n2() // Com n = 2, vão existir várias soluções , porém todas vão ser com a = b
{
        UINT MAX = 1;
        while (1)
        {
                for(int a = 1; a <= MAX; a++)
                  for(int b = 1; b <= MAX; b++)
                        for(int c = 1; c <= MAX; c++)
                                if ((a*a) == ((b*b) + (c*c))) { printf("A = %d (%d) = ( B = %d (%d) + C = %d (%d) )\n", a, a*a,  b, b*b, c, c*c); return 1;}
          MAX++;
  }
   return 0;
}


int fermat_n3()  //  n > 3 nunca vai ter solução, portanto isso seria um loop eterno.
{
        UINT MAX = 1;
        while (1)
        {
                for(int a = 1; a <= MAX; a++)
                        for(int b = 1; b <= MAX; b++)
                                for(int c = 1; c <= MAX; c++)
                                        if ((a*a*a) == ((b*b*b) + (c*c*c))) { printf("A = %d | B = %d C = %d\n", a, b, c); return 1;}
          MAX++;
  }
   return 0;
}

int main()
{
        if (fermat_n2())
                puts("\n\x1b[32mREALMENTE, O TEOREMA DE FERMAT EH REAL!\x1b[33m");

        puts("VEFIFICANDO SE EH IRREAL\x1b[0m");

        if (fermat_n3())
                puts("\nO TEOREMA DE FERMAT EH FALEO!!!");
        return 0;
}
