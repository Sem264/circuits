#include "stdio.h"
#include "stdlib.h"

int main(void){
    printf("Enter the first sparse vector:\n");
    char* inputLine = (char*) malloc(sizeof(char)*256);
    int vec1Size = 10;
    int* sparseVector1 = (int*) malloc(sizeof(int)*vec1Size);
    int* orderVector1;
    int* valuesVector1;
    if(fgets(inputLine, 256, stdin)!=NULL){
        int indexLine = 0;
        int indexInSparseVector1 = 0;
        while(inputLine[indexLine]){
            if(indexInSparseVector1>=vec1Size){
                vec1Size*=2;
                sparseVector1 = (int*) realloc(sparseVector1, vec1Size);
            }
            if(inputLine[indexLine] == '0'){
                sparseVector1[indexInSparseVector1++] = 0;
                indexLine+=2;
            }else if(inputLine[indexLine] != '0'){
                int negative = (inputLine[indexLine] == '-')? 1: 0;
                if(negative == 1){
                    indexLine++;
                }
                int number = 0;
                while(inputLine[indexLine]!=',' && inputLine[indexLine]!='\n'){
                    number*=10;
                    number += (inputLine[indexLine]-48);
                    indexLine++;
                }
                 sparseVector1[indexInSparseVector1++] = (negative==1)? (-number) :number;
                indexLine++;
            }
        }
        printf("The first sparse vector is:\n");
        for(int k = 0; k<indexInSparseVector1; k++){
            printf("%i, ",sparseVector1[k]);
        }

        orderVector1 = (int*) malloc(sizeof(int)*indexLine);
        valuesVector1 = (int*) malloc(sizeof(int)*indexLine);
        int valuesVector1Index = 0;
        int i;
        for(i = 0; i<indexInSparseVector1; i++){
            if(sparseVector1[i]==0){
                orderVector1[i] = 0;
            }else{
                orderVector1[i] = 1;
                valuesVector1[valuesVector1Index++] = sparseVector1[i];
            }
        }
        
        
        printf("\n");

        printf("The first order vector is:\n");
        for(int k = 0; k<indexInSparseVector1; k++){
            printf("%i, ",orderVector1[k]);
        }
        printf("\n");

        printf("The first values vector is:\n");
        for(int k = 0; k<valuesVector1Index; k++){
            printf("%i, ",valuesVector1[k]);
        }
        printf("\n");

    
        printf("Enter the second sparse vector:\n");
        char* inputLine2 = (char*) malloc(sizeof(char)*256);
        int vec2Size = 10;
        int* sparseVector2 = (int*) malloc(sizeof(int)*vec2Size);
        int* orderVector2;
        int* valuesVector2;
        if(fgets(inputLine2, 256, stdin)!=NULL){
            int indexLine2 = 0;
            int indexInSparseVector2 = 0;
            while(inputLine2[indexLine2]){
                if(indexInSparseVector2>=vec2Size){
                    vec2Size*=2;
                    sparseVector2 = (int*) realloc(sparseVector2, vec2Size);
                }
                if(inputLine2[indexLine2] == '0'){
                    sparseVector2[indexInSparseVector2++] = 0;
                    indexLine2+=2;
                }else if(inputLine2[indexLine2] != '0'){
                    int negative = (inputLine2[indexLine2] == '-')? 1: 0;
                    if(negative == 1){
                        indexLine2++;
                    }
                    int number = 0;
                    while(inputLine2[indexLine2]!=',' && inputLine2[indexLine2]!='\n'){
                        number*=10;
                        number += (inputLine2[indexLine2]-48);
                        indexLine2++;
                    }
                    sparseVector2[indexInSparseVector2++] = (negative==1)? (-number) :number;
                    indexLine2++;
                }
            }
            printf("The second sparse vector is:\n");
            for(int k = 0; k<indexInSparseVector2; k++){
                printf("%i, ",sparseVector2[k]);
            }

            orderVector2 = (int*) malloc(sizeof(int)*indexLine2);
            valuesVector2 = (int*) malloc(sizeof(int)*indexLine2);
            int valuesVector2Index = 0;
            int i;
            for(i = 0; i<indexInSparseVector2; i++){
                if(sparseVector2[i]==0){
                    orderVector2[i] = 0;
                }else{
                    orderVector2[i] = 1;
                    valuesVector2[valuesVector2Index++] = sparseVector2[i];
                }
            }
            
            
            printf("\n");

            printf("The second order vector is:\n");
            for(int k = 0; k<indexInSparseVector2; k++){
                printf("%i, ",orderVector2[k]);
            }
            printf("\n");

            printf("The second values vector is:\n");
            for(int k = 0; k<valuesVector2Index; k++){
                printf("%i, ",valuesVector2[k]);
            }
            printf("\n");

        

        //MULTIPLICATION OF SPARSE VECTORS
        int indexInValuesVector1 = 0;
        int indexInValuesVector2 = 0;
        int commonCounter = (indexInSparseVector1>=indexInSparseVector2) ? indexInSparseVector2 : indexInSparseVector1;
        int* resVector = (int*) malloc(sizeof(int)*commonCounter);
        int resVectorIndex = 0;
        int indexCounter = 0;
        while(indexCounter<commonCounter){
            if(orderVector1[indexCounter]==0 && orderVector2[indexCounter]!=0){
                indexInValuesVector2++;
                indexCounter++;
            }else if(orderVector1[indexCounter]!=0 && orderVector2[indexCounter]==0){
                indexInValuesVector1++;
                indexCounter++;
            }else if(orderVector1[indexCounter]!=0 && orderVector2[indexCounter]!=0){
                resVector[resVectorIndex++] = valuesVector1[indexInValuesVector1++]*valuesVector2[indexInValuesVector2++];
                indexCounter++;
            }else{
                indexCounter++;
            }
        }
        printf("The resultant vector is:\n");
        for(int k = 0; k<resVectorIndex; k++){
            printf("%i, ",resVector[k]);
        }
        return 0;
        }
    }
}