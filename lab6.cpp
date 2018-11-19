#include <iostream>

using namespace std;

class Vehicle{
    public:
        Vehicle(int weight_a, int manYear_a){
            weight = weight_a;
            manYear = manYear_a;
        }
        int getWeight(){
            return weight;
        }
        int getManYear(){
            return manYear;
        }
    private:
        int weight;
        int manYear;
};

class Car:public Vehicle{
    public:
        Car(int weight_a, int manYear_a, int numWheels_a):
                Vehicle(weight_a, manYear_a), numWheels(numWheels_a), category('E'){}
        int getNumWheels(){
            return numWheels;
        }
        char getCategory(){
            return category;
        }
        friend ostream& operator<<(ostream& cout, Car& car1);
    private:
        int numWheels;
        char category;
};

ostream& operator<<(ostream& cout, Car& car){
    cout<<"Car\nWeight: "<<car.getWeight()<<"\n"
        <<"Category: "<<car.getCategory()<<"\n"
        <<"Year: "<<car.getManYear()<<"\n"
        <<"Wheels: "<<car.numWheels<<endl;
    return cout;
}

class Boat:public Vehicle{
    public:
        Boat(int weight_a, int manYear_a, int maxDepth_a):
                Vehicle(weight_a, manYear_a), maxDepth(maxDepth_a){}
        int getMaxDepth(){
            return maxDepth;
        }
        friend ostream& operator<<(ostream& cout, Boat& boat);
    private:
        int maxDepth;
};

ostream& operator<<(ostream& cout, Boat& boat){
    cout<<"Boat\nWeight: "<<boat.getWeight()<<"\n"
        <<"Year: "<<boat.getManYear()<<"\n"
        <<"Max depth: "<<boat.maxDepth<<endl;
    return cout;
}

class AmphibiousCar:public Boat, public Car{
    public:
        AmphibiousCar(int weight_a, int manYear_a, int maxDepth_a, int numWheels_a):
                Boat(weight_a, manYear_a, maxDepth_a), Car(weight_a, manYear_a, numWheels_a){}
        friend ostream& operator<<(ostream& cout, AmphibiousCar& aCar); 
};

ostream& operator<<(ostream& cout, AmphibiousCar& aCar){
    cout<<"Amphibious Car\nWeight: "<<aCar.Boat::getWeight()<<"\n"
        <<"Category: "<<aCar.getCategory()<<"\n"
        <<"Year: "<<aCar.Car::getManYear()<<"\n"
        <<"Max depth: "<<aCar.getMaxDepth()<<endl;
    return cout;
}

int main(void){
    int weight;
    int year;
    int wheelsNum;
    int maxDepth;
    Boat* boat;
    Car* car;
    AmphibiousCar* aCar;
    printf("Enter the values for the car (weight, year, wheels): ");
    if(scanf("%i,%i,%i", &weight, &year, &wheelsNum)!=-1){
        if(weight<0 || year<0 || wheelsNum<0){
            printf("Enter correct values");
            return 1;
        }
        car = new Car(weight,year,wheelsNum);
    }
    printf("Enter the values for the boat (weight, year, depth): ");
    if(scanf("%i,%i,%i", &weight, &year, &maxDepth)!=-1){
        if(weight<0 || year<0 || maxDepth<0){
            printf("Enter correct values");
            return 1;
        }
        boat = new Boat(weight,year,maxDepth);
    }
    printf("Enter the values for the amphibious car (weight, year, depth, wheels): ");
    if(scanf("%i,%i,%i,%i", &weight, &year, &maxDepth, &wheelsNum)!=-1){
        if(weight<0 || year<0 || wheelsNum<0 || maxDepth<0){
            printf("Enter correct values");
            return 1;
        }
        aCar = new AmphibiousCar(weight,year,maxDepth, wheelsNum);
    }
    cout<<*car<<endl;
    cout<<*boat<<endl;
    cout<<*aCar<<endl;
    return 0;
}