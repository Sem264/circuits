#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include <cmath>
#include "time.h"
using namespace std;

template<typename T>
class Stack{
    private:
        T* LIFOQueue;
        int queueSize;
        int queueIndex;
    public:
        Stack(int queueSize_a):queueSize(queueSize_a),queueIndex(0){
            LIFOQueue = (T*) malloc(sizeof(T)*queueSize);
        }
        void push(T element);
        T pop();
        T getTop();
        int getQueueSize(){
            return queueSize;
        }
        int getQueueIndex(){
            return queueIndex;
        }
        ~Stack(){
            free(LIFOQueue);
        }
};

template<typename T>
void Stack<T>::push(T element){
    if(queueIndex>=queueSize){
        queueSize*=2;
        LIFOQueue = (T*) realloc(LIFOQueue, sizeof(T)*queueSize);
    }
    LIFOQueue[queueIndex++] = element;
}

template<typename T>
T Stack<T>::pop(){
    if(queueIndex>0)
        return LIFOQueue[--queueIndex];
    printf("No more elements");
}

template<typename T>
T Stack<T>::getTop(){
    if(queueIndex>0){
        return LIFOQueue[queueIndex-1];
    }
    printf("No more elements");
}

int main(void){
    srand(time(NULL));
    Stack<int> intStack = Stack<int>(10);
    int queueSize = intStack.getQueueSize();
    for(int i = 0; i<queueSize; i++){
        int random = rand()%1000;
        intStack.push(random);
    }
    queueSize = intStack.getQueueSize();
    printf("Size: %i\n", queueSize); 
    printf("Top Element: %i\n", intStack.getTop());
    for(int i = 0; i<queueSize;i++){
        printf("%i\n", intStack.pop());
    }  
    
    Stack<float> floatStack = Stack<float>(10);
    queueSize = floatStack.getQueueSize();
    for(int i = 0; i<queueSize; i++){
        floatStack.push(1.25*i);
    }
    queueSize = floatStack.getQueueSize();
    printf("Size: %i\n", queueSize); 
    printf("Top Element: %f\n", floatStack.getTop());
    for(int i = 0; i<queueSize;i++){
        printf("%f\n", floatStack.pop());
    }

    Stack<char> charStack = Stack<char>(10);
    queueSize = charStack.getQueueSize();
    printf("Size: %i\n", queueSize);
    for(int i = 0; i<queueSize; i++){
        charStack.push('A'+i);
    }
    queueSize = charStack.getQueueSize();
    printf("Size: %i\n", queueSize); 
    printf("Top Element: %i\n", charStack.getTop());
    for(int i = 0; i<queueSize;i++){
        printf("%i\n", charStack.pop());
    }
    return 1;
}