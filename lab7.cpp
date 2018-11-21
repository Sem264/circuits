// Example program
#include <iostream>
#include <string>
#include <cmath>
#include "stdlib.h"

using namespace std;

class Shape{
    public:
        virtual void draw() = 0;
        virtual void setArea(float area_a) = 0;
        virtual void calculateArea() = 0;   
        Shape(){}
}; 

class TwoDimensionalShape:public Shape{
    public:
        TwoDimensionalShape(){}  
        void setArea(float area_a){
            area = area_a;
        }
        float getArea(){ return area; }
    private:
        float area;
};


class Square:public TwoDimensionalShape{
    public:
        Square(int x_a, int y_a, float a_a):x(x_a),y(y_a),a(a_a){}
        int getX(){return x;}
        int getY(){return y;}
        float getA(){return a;}
        void calculateArea(){
            float areaS = a*a;
            setArea(areaS);
        }
        void draw(){
            float x1 = x-a/2;   
            float x2 = x+a/2; 
            float y1 = y-a/2; 
            float y2 = y+a/2; 
            cout<<"The square's vertices are:\n"
                <<"1st: ("<<x1<<","<<y1<<")\n"
                <<"2nd: ("<<x1<<","<<y2<<")\n"
                <<"3rd: ("<<x2<<","<<y1<<")\n"
                <<"4th: ("<<x2<<","<<y2<<")"<<endl;
                calculateArea();
                printf("Area is: %f\n",getArea());
        }
        
    private:
        int x;
        int y;
        float a;
};

class Rectangle:public TwoDimensionalShape{
    public:
        Rectangle(int x_a, int y_a, float a_a, float b_a):x(x_a),y(y_a),a(a_a), b(b_a){}
        int getX(){return x;}
        int getY(){return y;}
        float getA(){return a;}
        float getB(){return b;}
        void calculateArea(){
            float areaS = a*b;
            setArea(areaS);
        }
        void draw(){
            float x1 = x-a/2;   
            float x2 = x+a/2; 
            float y1 = y-b/2; 
            float y2 = y+b/2; 
            cout<<"The rectangle's vertices are at:\n"
                <<"1st: ("<<x1<<","<<y1<<")\n"
                <<"2nd: ("<<x1<<","<<y2<<")\n"
                <<"3rd: ("<<x2<<","<<y1<<")\n"
                <<"4th: ("<<x2<<","<<y2<<")\n";
            calculateArea();
            printf("Area is: %f\n",getArea());
        }
    private:
        int x;
        int y;
        float a;
        float b;
};

class Triangle:public TwoDimensionalShape{
    public:
        Triangle(int x_a, int y_a, float a_a, float b_a, float c_a):x(x_a),y(y_a),a(a_a), b(b_a), c(c_a){}
        int getX(){return x;}
        int getY(){return y;}
        float getA(){return a;}
        float getB(){return b;}
        float getC(){return c;}
        void calculateArea(){
            float cosA_B = (-c*c+a*a+b*b)/(2*a*b);
            float sinA_B = sqrt(1-cosA_B*cosA_B);
            float areaS = 0.5*a*b*sinA_B;
            setArea(areaS);
        }
        void draw(){
            cout<<"The triangle's is centered at:("<<x<<","<<y<<") with sides:\n"
                <<"a: "<<a<<"\n"
                <<"b: "<<b<<"\n"
                <<"c: "<<c<<endl;
            calculateArea();
			printf("Area is: %f\n",getArea());
        }
    private:
        int x;
        int y;
        float a;
        float b;
        float c;
};

class Circle:public TwoDimensionalShape{
    public:
        Circle(int x_a, int y_a, float r_a):x(x_a),y(y_a),r(r_a){}
        int getX(){return x;}
        int getY(){return y;}
        float getR(){return r;}
		void calculateArea(){
            float areaS = 3.14*r*r;
            setArea(areaS);
        }
        void draw(){
            cout<<"The circle is centered at:("<<x<<","<<y<<") with radius: "<<r<<"\n";
            calculateArea();
			printf("Area is: %f\n",getArea());
        }
    private:
        int x;
        int y;
        float r;
};



int main()
{
    int x;
    int y;
    float a;
    float b;
    float c;
    float r;
    Square* square;
    Rectangle* rectangle;
    Triangle* triangle;
    Circle* circle;
    printf("Enter for the square (x,y,a):\n");
    if(scanf("%i,%i,%f", &x,&y,&a)!=-1){
        if(x<0 || y<0 || a<0.0){
            printf("Entered the wrong values");
            return 1;
        }
        square = new Square(x,y,a);
        (*square).draw();
    }
    printf("Enter for the rectangle (x,y,a,b):\n");
    if(scanf("%i,%i,%f,%f", &x,&y,&a,&b)!=-1){
        if(x<0 || y<0 || a<0.0 || b<0.0){
            printf("Entered the wrong values");
            return 1;
        }
        rectangle = new Rectangle(x,y,a,b);
        (*rectangle).draw();
    }
    printf("Enter for the triangle (x,y,a,b,c):\n");
    if(scanf("%i,%i,%f,%f,%f", &x,&y,&a,&b,&c)!=-1){
        if(x<0 || y<0 || a<0.0 || b<0.0 || c<0.0){
            printf("Entered the wrong values");
            return 1;
        }
        triangle = new Triangle(x,y,a,b,c);
        (*triangle).draw();
    }
    printf("Enter for the circle (x,y,r):\n");
    if(scanf("%i,%i,%f", &x,&y,&r)!=-1){
        if(x<0 || y<0 || r<0.0){
            printf("Entered the wrong values");
            return 1;
        }
        circle = new Circle(x,y,r);
        (*circle).draw();
    } 
    
    return 0;
}