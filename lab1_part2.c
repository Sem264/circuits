#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter the min number of the range: ");
    int minInt = 0;
    int maxInt = 0;
    int arraySize = 32;
    int* primeNumbers = malloc(sizeof(int) * arraySize);
    int pointer = 0;
    if(scanf("%i", &minInt)==1){
        printf("Enter the max number of the range: ");
        if(scanf("%i", &maxInt)==1){
            if(maxInt>minInt){
                int isDivisible = 0;
                for(int i = minInt; i <= maxInt; i++){
                    for(int j = 2; j<i; j++){
                        if(i%j==0)
                            isDivisible = 1;
                    }
                    if(isDivisible == 0){
                        if(pointer>=arraySize){
                            arraySize*=2;
                            primeNumbers = realloc(primeNumbers, arraySize);
                        }
                        primeNumbers[pointer++] = i;
                    }
                    isDivisible = 0;
                }
                for(int i = 0; primeNumbers[i]!='\0'; i++){
                    printf("%i\n", primeNumbers[i]);
                }
            }
        }
    }
    return 0;
}
