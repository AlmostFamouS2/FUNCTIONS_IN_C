#include <stdio.h>

// But good luck on writing an example that runs faster with __builtin_expect than without,
// CPUs are really smart these days.

#define like(x) __builtin_expect((x), 1)   // Usar quando as chances de ser verdade sao maiores
#define unlike(x) __builtin_expect((x), 0)  // Usar quando as chances de ser verdade sao menores

int main(int argc, char *argv[]){
	if( ! *++argv ) return 1; // Sempre quando fazemos isso, o ponteiro vai para frente, portanto argv[1] vira  argv[0]

	if(unlike(atoi(argv[0]) == 42))
		printf("Isso foi o esperado pelo Branch Prediction, e nao precisou de clocks a mais para operar o PIPELINE");

return 0;
}
