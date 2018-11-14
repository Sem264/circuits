#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class ArabianNumbers{
    public:
        ArabianNumbers(int number=0):intValue(number){}
        virtual void printValue(){printf("%i\n",intValue);}
    protected:
        int intValue;
};

class RomanNumbers:public ArabianNumbers{
    public:
        RomanNumbers(int number=0):ArabianNumbers(number){}
        void printValue();
};

void RomanNumbers::printValue(){
    int piece;
    string roman;

    if((intValue>=4000) || (intValue<=0)){
        cout<<"Invalid Integer"<<endl;
    }else{
        if(intValue>=1000){
            piece = (intValue/1000);
            for(int i = 0; i < piece; i++)
                roman+='M';
            intValue %= 1000;
        }

        if(intValue >= 100){
            piece = (intValue/100);
            if(piece == 9){
                roman += "CM";
            }else if(piece>=5){
                roman+='D';
                for(int i = 0; i<piece-5; i++)
                    roman+='C';
            }else if(piece == 4){
                roman += "CD";
            }else if(piece>=1){
                for(int i = 0; i<piece; i++)
                    roman+='C';
            }
            intValue %= 100;
        }

        if(intValue>=10){
            piece = (intValue/10);
            if(piece == 9){
                roman+="XC";
            }else if(piece>=5){
                roman+='L';
                for(int i = 0; i<piece-5; i++)
                    roman+='X';
            }else if(piece == 4){
                roman += "XL";
            }else if(piece>=1){
                for(int i = 0; i<piece; i++)
                    roman+='X';
            }
            intValue %= 10;
        }

        if(intValue>=1){
            piece = intValue;
            if(piece == 9){
                roman+="IX";
            }else if(piece>=5){
                roman+='V';
                for(int i = piece; i<9; i++)
                    roman+='I';
            }else if(piece == 4){
                roman += "IV";
            }else if(piece>=1){
                for(int i = 0; i<piece; i++)
                    roman+='I';
            }
        }
        cout<<roman<<endl;
    }
}

int main(){
    printf("Enter a number to be represented by arabic and roman numerals: ");
    int number = 0;
    if(scanf("%i",&number)!=-1){
        ArabianNumbers aNum = ArabianNumbers(number);
        aNum.printValue();
        RomanNumbers rNum = RomanNumbers(number);
        rNum.printValue();
    }
    return 0;
}