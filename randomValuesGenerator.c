#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    FILE* allValuesFile = fopen("all_values.txt", "w");
    srand(time(NULL));
    for(int i = 1; i <= 5; i++){
        int salesPersonID = i;
        int salesDaysPerMonth = rand() % 30;
        for(int j = 1; j <= salesDaysPerMonth; j++){
            int salesSlipsPerDay = rand() % 4;
            for(int k = 1; k <= salesSlipsPerDay; k++){
                int productID = rand() % 4;
                int valueOfOneProduct = rand() % 100;
                int numberOfSoldProducts = rand() % 10;
                int totalValue = valueOfOneProduct * numberOfSoldProducts;
                fprintf(allValuesFile,"%i,%i,%i \n", salesPersonID, productID, totalValue);
            }
        }
    }
    fclose(allValuesFile);
    return 0;
}