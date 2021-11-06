// gcc calculadora.c -o calculadora -O2 -w

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int msleep(unsigned int tms) {
  return usleep(tms * 1000);
}

void pslp(const char *msg){
    printf("%s\n",msg);
    msleep(500);
}

void banner()
{
    pslp("--------------------------------------------------------------------------------");
    pslp("      CRIADO POR: VITOR GUSMAO                                                 |");
    pslp("    [+]  DISCORD: Nobody_KNOWS#9961                                            |");
    pslp("    [+]  INSTAGRAM: @gusmaospeedcuber                                          |");
    pslp("    [+]  LINKEDIN: https://www.linkedin.com/in/vitor-gusm%C3%A3o-a9155b202/    |");
    pslp("--------------------------------------------------------------------------------");
}

unsigned long pow_recursive(unsigned long n, int times);
unsigned long power(unsigned long n, int times);
// ---------------------------------------------------->
unsigned char conf(){
    printf("\x1b[33mDigite:\n\n1 - SOMA\n2 - SUBTRACAO\n3 - Multiplicao\n4 - Divisao\n5 - Potenciacao \n\n>>> ");

    unsigned char r;
    scanf("%c", &r);

    while(r < '1' || r > '5'){
        fprintf(stderr, "\x1b[31mDigite um numero entre 1 e 4, por favor!\n\x1b[0m");
        printf("\x1b[32mDigite:\n\n[ 1 ]-> SOMA\n[ 2 ] -> SUBTRACAO\n[ 3 ] -> Multiplicao\n[ 4 ] -> Divisao\n[ 5 ] -> Potenciacao\n\n>>> \x1b[33m");
        scanf("%c", &r);
    }

    return r;
}

// -------------------------------> MAIN <-----------------------------------------------
int main(int argc, char argv[]){
    banner();

    unsigned char r;
    r = conf();
    unsigned long nums[2] = {0};


    if(argc != 3)
    {
        printf("Digite o primeiro operando: ");
        scanf("%d", &nums[0]);
        printf("Digite o segundo operando: ");
        scanf("%d", &nums[1]);
    }

    else {
        nums[0] = atol(argv[1]);
        nums[1] = atol(argv[2]);

        if (!nums[0] || !nums[1]){
            fprintf(stderr, "\x1b[31m MODO DE USO: %s <NUMBER_1> <NUMBER_2>\x1b[0m", argv[0]);
            return 1;
        }
    }

    if (r == '5' && power(nums[0], nums[1]) < 0) // Ocorreu um overflow
    {
        fprintf(stderr, "\x1b[31m Ocorreu um overflow... Tente novamente mais tarde.\x1b[0m", argv[0]);
        return 1;
    }

// ------------------------------> Switch <==============================================================
    switch(r)
    {
        case '1':
            printf("RESULTADO: \x1b[32m%ld + %ld = [ %ld ]\n\x1b[0m", nums[0], nums[1], nums[0] + nums[1]);
            return 0;

        case '2':
            printf("RESULTADO: \x1b[32m%ld - %ld = [ %ld ]\n\x1b[0m", nums[0], nums[1], nums[0] - nums[1]);
            return 0;

        case '3':
            printf("RESULTADO: \x1b[32m%ld * %ld = [ %ld ]\n\x1b[0m", nums[0], nums[1], nums[0] * nums[1]);
            return 0;

        case '4':
            printf("RESULTADO: \x1b[32m%ld / %ld = [ %.2f ]\n\x1b[0m", nums[0], nums[1], nums[0] / nums[1]);
            return 0;

        case '5':
            printf("RESULTADO: \x1b[32m%ld ^ %ld = [ %ld ]\n", nums[0], nums[1], power(nums[0], nums[1]));
            return 0;
    }
// ------------------------------> END Switch <==============================================================

    printf("\n >>>>>>> %ld <<<<< \n", power(3,30));

return 0;
}

// --------------------------------------------------------------------->
unsigned long pow_recursive(unsigned long n, int times)
{
    if (times == 1)
        return n;
    return n * pow_recursive(n, times-1);
}

unsigned long power(unsigned long n, int times)
{
    unsigned long number = n;

    if(times <= 50){
        number = pow_recursive(n, times);
        return number;
    }

    else {
        unsigned long aux = n;

        #pragma omp parallel   // Isso faz usar todos os nucleos do processador ao mesmo tempo, ao inves de um apenas  para processar o loop
        while(times--)
            n *= aux;
    }

return n;
}
