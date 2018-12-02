#include <iostream>
#include "stdio.h"
#include "stdlib.h"

using namespace std;

class Point{
    private:
        float x;
        float y;
    public:
        Point(float x_a, float y_a):x(x_a),y(y_a){}
        float getX() const{
            return x;
        }
        float getY() const{
            return y;
        }
};


template <typename T>
void sort(T* arr, int size, bool comp(T*, T*)) {
    for(int i = 0; i<size-1; i++){
        for(int j = 0; j<size-i-1; j++){
            if(comp(&arr[j],&arr[j+1])){
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

template <typename T>
bool compareX(T* a, T* b){
    return ((*a).getX() - (*b).getX());
}

template <typename T>
bool compareY(T* a, T* b){
    return ((*a).getY() - (*b).getY());
}

int main() {
    float x, y;
    char line[256];
    int pointsSize = 10;
    Point* points = (Point*) malloc(sizeof(Point)*pointsSize);
    int pointsIndex = 0;
    printf("Enter the points in the form (x,y) or press Q to quit: ");
    if(fgets(line, sizeof(line), stdin)!=NULL){
        for(int indexLine = 0; line[indexLine]!='Q'; indexLine+=2){
            float x = 0.0;
            float y = 0.0;
            float tempFloat = 0.0;
            int negative = 0;
            int dot = 0;
            int degreeAfterDot = 1;
            while(line[indexLine]!=','){
                if(line[indexLine]=='('){
                    indexLine++;
                    if(line[indexLine]=='-'){
                        negative = 1;   
                        indexLine++;
                    }
                }
                if(line[indexLine]=='.'){
                    dot = 1;
                    indexLine++;
                }
                if(dot==0){
                    tempFloat = line[indexLine]-48;
                    x*=10.0;
                    x+=tempFloat;
                    indexLine++;
                }else if(dot==1){
                    tempFloat = line[indexLine]-48;
                    for(int k = 0; k<degreeAfterDot; k++)
                        tempFloat*=0.1;
                    x+=tempFloat;
                    indexLine++;
                    degreeAfterDot++;
                }
            }
            if(negative == 1)
                x = -x;
                
            tempFloat = 0.0;
            negative = 0;
            dot = 0;
            degreeAfterDot = 1;
            while(line[indexLine]!=')'){
                if(line[indexLine]==','){
                    indexLine++;
                    if(line[indexLine]=='-'){
                        negative = 1;   
                        indexLine++;
                    }
                }
                if(line[indexLine]=='.'){
                    dot = 1;
                    indexLine++;
                }
                if(dot==0){
                    tempFloat = line[indexLine]-48;
                    y*=10.0;
                    y+=tempFloat;
                    indexLine++;
                }else if(dot==1){
                    tempFloat = line[indexLine]-48;
                    for(int k = 0; k<degreeAfterDot; k++)
                        tempFloat*=0.1;
                    y+=tempFloat;
                    indexLine++;
                    degreeAfterDot++;
                }
            }
            if(negative == 1)
                y = -y;
                
            Point newPoint(x,y);
            if(pointsIndex>=pointsSize){
                pointsSize*=2;
                points = (Point*) realloc(points, sizeof(Point*)*pointsSize);
            }
            points[pointsIndex++] = newPoint;
        }
    }        
    pointsSize = pointsIndex;
    points = (Point*) realloc(points, sizeof(Point*)*pointsSize);
    printf("Entered points are:\n");
    for(int i = 0; i<pointsIndex; i++){
        printf("(%.3f,%.3f) ", points[i].getX(), points[i].getY());
    }
    printf("\n");
    //NOW HAVE POINTS HERE
    sort<Point>(points, pointsSize, compareX<Point>); 
    printf("Sorted by x:\n");
    for(int i = 0; i<pointsIndex; i++){
        printf("(%.3f,%.3f) ", points[i].getX(), points[i].getY());
    }
    printf("\n");

    sort<Point>(points, pointsSize, compareY<Point>);
    printf("Sorted by y:\n");
    for(int i = 0; i<pointsIndex; i++){
        printf("(%.3f,%.3f) ", points[i].getX(), points[i].getY());
    }
    printf("\n");
  return 0;
}

//(-3.5,9.7),(0.7,-13.154),(11.8,-172.15),Q




