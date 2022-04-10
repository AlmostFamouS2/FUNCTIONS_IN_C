void main(){
        int A[5][5] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25}};

        int B[25] = {0};

        for(int i = 0; i < 5; i++)
                for(int j = 0; j < 5; j++)
                        if (i != j)
                                B[(i*5) + j] = sum(A[i][j]);
                        else
                                B[i+j] = fat(A[i][j]);   // if (A[1,1] || A[2,2])   Diagonal principal, fatorial

        for(int i = 0; i < 25; i++)
                printf("%d ", B[i]);

        puts("");
}
