#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

class Rectangle{
    public:
        Rectangle(float a_A, float b_A):a(a_A),b(b_A){};
        Rectangle(){a = 0.0; b = 0.0;}
        virtual float area(){return a*b;}
        virtual float diagonal(){return sqrt(a*a+b*b);}
        float getA(){return a;}
        float getB(){return b;}
    private:
        float a;
        float b;
};

class Cuboid:public Rectangle{
    public:
        Cuboid(float a_A, float b_A, float c_A):Rectangle(a_A,b_A),c(c_A){};
        Cuboid(){c = 0.0;}
        float area(){
            return 2*c*(getA()+getB());
        }
        float diagonal(){
            return sqrt(getA()*getA()+getB()*getB()+c*c);
        }
    private:
        float c;
};


int main(void){
    printf("Enter the values of a and b for the rectangle: ");
    float a = 0;
    float b = 0;
    float c = 0;
    if(scanf("%f,%f", &a,&b)!=-1){
        if(a<0 || b<0){
            printf("Enter correct values");
            return 1;
        }
        Rectangle rect = Rectangle(a,b);
        cout<<"Area: "<<rect.area()<<endl;
        cout<<"Diagonal: "<<rect.diagonal()<<endl;
    }
    printf("Enter the values of a, b and c for the cuboid: \n");
    if(scanf("%f,%f,%f", &a,&b,&c)!=-1){
        if(a<0 || b<0){
            printf("Enter correct values");
            return 1;
        }
        Cuboid cub = Cuboid(a,b,c);
        cout<<"Area: "<<cub.area()<<endl;
        cout<<"Diagonal: "<<cub.diagonal()<<endl;
    }
    return 0;
}