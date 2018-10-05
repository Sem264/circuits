#include <stdio.h>
#include <stdlib.h>

int main()
{
    char line[256];
    int isNegative;
    int number;
    int* matrixRow = 0;
    int** matrix = malloc(sizeof(int)*10);
    int matrixRowPointer = 0;
    int matrixColNumber = 10;
    int rowSize = 10;
    int pointerPerRow;
    int matrixColumnNumber = 0;
    int matrixRowNumber = 0;
    int numberOfRunsOfTheLoop = 0;
    int checkedLength1 = 0;
    while(fgets(line, sizeof(line), stdin)!=NULL){
        isNegative = 0;
        number = 0;
        pointerPerRow = 0;
        matrixRow = malloc(sizeof(int)*rowSize);
        for(int i = 0; line[i]!='\0'; i++){
            if((line[i]=='-' && i>0 && line[i-1]==' ') || (i==0 && line[i]=='-')){
                isNegative = 1;
            }else if(line[i]>='0' && line[i]<='9'){
                number = number * 10 + (line[i] - 48);
            }else if(line[i]=='\n' || line[i]==' '){
                if(isNegative == 1)
                    number = -number;
                if(pointerPerRow==rowSize){
                    rowSize*=2;
                    matrixRow = realloc(matrixRow,rowSize);
                }
                matrixRow[pointerPerRow++] = number;
                if(line[i]=='\n'){
                    if(matrixRowPointer==matrixColNumber){
                        matrixColNumber*=2;
                        matrix = realloc(matrix, matrixColNumber);
                    }
                    matrix[matrixRowPointer++] = matrixRow;
                    if(pointerPerRow>matrixColumnNumber && checkedLength1 == 1){
                        printf("Rows should be consistent in size");
                        return 1;
                    }
                    if(numberOfRunsOfTheLoop==0){
                        matrixColumnNumber = pointerPerRow;
                        checkedLength1++;
                        numberOfRunsOfTheLoop++;
                    }
                }
                number = 0;
                isNegative = 0;
            }else{
                printf("Wrong input");
                return 1;
            }
        }
    }
    matrixRowNumber = matrixRowPointer;

    // HERE WE HAVE THE FIRST MATRIX READY
    char line2[256];
    int isNegative2;
    int number2;
    int* matrixRow2 = 0;
    int** matrix2 = malloc(sizeof(int)*10);
    int matrixRowPointer2 = 0;
    int matrixColNumber2 = 10;
    int rowSize2 = 10;
    int pointerPerRow2;
    int matrixColumnNumber2 = 0;
    int matrixRowNumber2 = 0;
    int numberOfRunsOfTheLoop2 = 0;
    int checkedLength2 = 0;
    while(fgets(line2, sizeof(line2), stdin)!=NULL){
        isNegative2 = 0;
        number2 = 0;
        pointerPerRow2 = 0;
        matrixRow2 = malloc(sizeof(int)*rowSize2);
        for(int i = 0; line2[i]!='\0'; i++){
            if((line2[i]=='-' && i>0 && line2[i-1]==' ') || (i==0 && line2[i]=='-')){
                isNegative2 = 1;
            }else if(line2[i]>='0' && line2[i]<='9'){
                number2 = number2 * 10 + (line2[i] - 48);
            }else if(line2[i]=='\n' || line2[i]==' '){
                if(isNegative2 == 1)
                    number2 = -number2;
                if(pointerPerRow2==rowSize2){
                    rowSize2*=2;
                    matrixRow2 = realloc(matrixRow2,rowSize2);
                }
                matrixRow2[pointerPerRow2++] = number2;
                if(line2[i]=='\n'){
                    if(matrixRowPointer2==matrixColNumber2){
                        matrixColNumber2*=2;
                        matrix2 = realloc(matrix2, matrixColNumber2);
                    }
                    if(pointerPerRow2>matrixColumnNumber2 && checkedLength2 == 1){
                        printf("Rows should be consistent in size");
                        return 1;
                    }
                    matrix2[matrixRowPointer2++] = matrixRow2;
                    if(numberOfRunsOfTheLoop2==0){
                        matrixColumnNumber2 = pointerPerRow2;
                        checkedLength2++;
                        numberOfRunsOfTheLoop2++;
                    }
                }
                number2 = 0;
                isNegative2 = 0;
            }else{
                printf("Wrong input");
                return 1;
            }
        }
    }
    matrixColumnNumber2 = pointerPerRow2;
    matrixRowNumber2 = matrixRowPointer2;
    int** matrix3 = malloc(sizeof(int*) * matrixRowNumber);
    int matrixRowPointer3 = 0;
    int *matrixRow3 = 0;
    int rowPointer3;
    int number3;
    if(matrixColumnNumber == matrixRowNumber2){
        for(int j = 0; j < matrixRowNumber; j++){
            rowPointer3 = 0;
            matrixRow3 = malloc(sizeof(int)*matrixRowNumber);
            for(int k = 0; k < matrixRowNumber; k++){
                number3 = 0;
                for(int i = 0; i < matrixColumnNumber; i++){
                    number3+=matrix[j][i]*matrix2[i][k];
                }
                matrixRow3[rowPointer3++] = number3;
            }
            matrix3[matrixRowPointer3++] = matrixRow3;
        }
        for(int j = 0; j < matrixRowNumber; j++){
            for(int i = 0; i < matrixColumnNumber2; i++){
                printf("%i ", matrix3[j][i]);
            }
            printf("\n");
        }
    }else{
        printf("Cannot multiply the given matrices");
    }
    return 0;
}
