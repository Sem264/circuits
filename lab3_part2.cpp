#include <stdio.h>
#include <iostream>
using namespace std;
class Complex{
    public:
        Complex operator+(Complex& number2);
        Complex operator-(Complex& number2);
        Complex operator*(Complex& number2);
        friend Complex operator/(Complex& number1, Complex& number2);
        friend ostream& operator<<(ostream& cout, Complex number);
        Complex(float realPart, float imgPart);
        float getReal(){
            return realPart;
        }
        float getImg(){
            return imgPart;
        }
    private:
        float realPart;
        float imgPart;
};

ostream& operator<<(ostream& cout, Complex number){
    cout<<"("<<number.getReal()<<","<<number.getImg()<<")"<<endl;
    return cout;
}

Complex::Complex(float realPart, float imgPart = 0){
    (*this).realPart = realPart;
    (*this).imgPart = imgPart;
}

Complex Complex::operator+(Complex& number2){
    float imgPartn = imgPart + number2.imgPart;
    float realPartn = realPart + number2.realPart;
    Complex resultComplex(realPartn, imgPartn);
    return resultComplex;
}

Complex Complex::operator-(Complex& number2){
    float imgPartn = imgPart - number2.imgPart;
    float realPartn = realPart - number2.realPart;
    Complex resultComplex(realPartn, imgPartn);
    return resultComplex;
}

Complex Complex::operator*(Complex& number2){
    float imgPartn = ((realPart * number2.imgPart) + (imgPart * number2.realPart));
    float realPartn = ((realPart * number2.realPart) - (imgPart * number2.imgPart));
    Complex resultComplex(realPartn, imgPartn);
    return resultComplex;
}

Complex operator/(Complex& number1, Complex& number2){
    float conjugateImg = -number2.imgPart;
    float imgPartn = number1.imgPart*number2.realPart + number1.realPart*conjugateImg;
    float realPartn = (number1.realPart*number2.realPart - number1.imgPart*conjugateImg)/((number2.realPart*number2.realPart)+(number2.imgPart*number2.imgPart));
    Complex resultComplex(realPartn, imgPartn);
    return resultComplex;
}

int main(void){
    printf("Enter the 1st complex number in the form of a,b: ");
    float realPart1 = 0;
    float imgPart1 = 0;
    if(scanf("%f,%f", &realPart1, &imgPart1)!=0){
        printf("Enter the 2nd complex number in the form of a,b: ");
        float realPart2 = 0;
        float imgPart2 = 0;
        if(scanf("%f,%f", &realPart2, &imgPart2)!=0){
            Complex complex1(realPart1, imgPart1);
            Complex complex2(realPart2, imgPart2);

            Complex c1_add_c2 = complex1 + complex2;
            Complex c1_sub_c2 = complex1.operator-(complex2);
            Complex c1_mul_c2 = complex1 * complex2;
            Complex c1_div_c2 = operator/(complex1, complex2);
/*             printf("The addition of two complex numbers: (%.2f,%.2f)\n", c1_add_c2.getReal(), c1_add_c2.getImg());
            printf("The subtraction of two complex numbers: (%.2f,%.2f)\n", c1_sub_c2.getReal(), c1_sub_c2.getImg());
            printf("The multiplication of two complex numbers: (%.2f,%.2f)\n", c1_mul_c2.getReal(), c1_mul_c2.getImg());
            printf("The division of two complex numbers: (%.2f,%.2f)\n", c1_div_c2.getReal(), c1_div_c2.getImg());
 */         cout<<c1_add_c2<<c1_sub_c2<<c1_mul_c2<<c1_div_c2;   
        }
    }
    return 0;
}