#include <stdio.h>
#include <stdlib.h>

typedef struct slipForOneDay{
	int salesPersonID;
	int productID;
	int valueSold;
} oneSlip;

int main(void)
{
	int size = 32;
	oneSlip* salesPersonsAndTheirSales[5];
	int salesPersonsAndTheirSalesIndexes[5] = {0,0,0,0,0};
	int multipleOfSize[5] = {1,1,1,1,1};
	for(int l = 0; l < 5; l++){
		salesPersonsAndTheirSales[l] = (oneSlip*) malloc(sizeof(oneSlip)*size*multipleOfSize[l]);
	}
	int salesPersonID;
	int productID;
	int totalValue;
	FILE* allValuesFile = fopen("all_values.txt", "r");
	int i = 0;
	while(fscanf(allValuesFile, "%i,%i,%i", &salesPersonID, &productID, &totalValue)>0){
		if(salesPersonsAndTheirSalesIndexes[salesPersonID-1]==(size*multipleOfSize[salesPersonID-1])){
			multipleOfSize[salesPersonID-1]++;
			salesPersonsAndTheirSales[salesPersonID-1] = (oneSlip*)realloc(salesPersonsAndTheirSales[salesPersonID-1], sizeof(oneSlip)*size*multipleOfSize[salesPersonID-1]);
		}
		oneSlip thisSaleSlip = {salesPersonID, productID, totalValue};
		salesPersonsAndTheirSales[salesPersonID-1][salesPersonsAndTheirSalesIndexes[salesPersonID-1]] = thisSaleSlip;
		salesPersonsAndTheirSalesIndexes[salesPersonID-1]++;
	}

	printf("Sales-%30s\n", "Products");
	printf("person %8d%8d%8d%8d%9s\n", 1, 2, 3, 4, "Total");

	for(int q = 0; q < 5; q++){
		int curSalesPersonID = q+1;
		int product_value1 = 0;
		int product_value2 = 0;
		int product_value3 = 0;
		int product_value4 = 0;
		int totalValue = 0;
		for(int w = 0; w < salesPersonsAndTheirSalesIndexes[q]; w++){
			if(salesPersonsAndTheirSales[q][w].productID == 0){
				product_value1+=salesPersonsAndTheirSales[q][w].valueSold;
			}else if(salesPersonsAndTheirSales[q][w].productID == 1){
				product_value2+=salesPersonsAndTheirSales[q][w].valueSold;
			}else if(salesPersonsAndTheirSales[q][w].productID == 2){
				product_value3+=salesPersonsAndTheirSales[q][w].valueSold;
			}else if(salesPersonsAndTheirSales[q][w].productID == 3){
				product_value4+=salesPersonsAndTheirSales[q][w].valueSold;
			}
			totalValue+=salesPersonsAndTheirSales[q][w].valueSold;
		}
 		totalValue = product_value1 + product_value2 + product_value3 + product_value4;
 		printf("%3i%14i%7i%7i%9i%7i\n", curSalesPersonID, product_value1, product_value2, product_value3, product_value4, totalValue);
	}
	   
	return 0;
}
