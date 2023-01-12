#include <stdio.h>
#include <inttypes.h>
#include <time.h>

// Create an algorithm to match the target with the sum of any 2 numbers in the array

int main(){
        uint8_t vec[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
        register int tam = sizeof(vec);

        srand(time(0));
        int gen = rand() % 10;
        register int target = 8 + gen;
        printf("\x1b[33m RANDOM NUM GENERATED: %d <=========================== \n\n\x1b[0m", target);

        for(int i = 0; i < tam-1; i++){
                for (int j = i+1; j < tam; j++){
                        if ((vec[j] + vec[i]) == target)
                                printf("FOUNDED: [ %d ] + [ %d ] = %d \n", vec[j], vec[i], target);
                }
        }

return 0;
}
