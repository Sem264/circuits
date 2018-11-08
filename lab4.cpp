#include <iostream>

using namespace std;

class Vehicle{
public:
    Vehicle(char* model_A, int numDoors_A, int numWheels_A, int numSits_A, float fuelCapacity_A, float secsTillHundred_A, int yearOfManufacturing_A, char category_A);

    char* getModel(){
        return model;
    }
    int getNumDoors(){
        return numDoors;
    }
    int getNumWheels(){
        return numWheels;
    }
    int getNumSits(){
        return numSits;
    }
    float getFuelCapacity(){
        return numSits;
    }
    float getSecsTillHundred(){
        return secsTillHundred;
    }
    int getYearOfManufacturing(){
        return yearOfManufacturing;
    }
    char getCategory(){
        return category;
    }
private:
    char* model;
    int numDoors;
    int numWheels;
    int numSits;
    float fuelCapacity;
    float secsTillHundred;
    int yearOfManufacturing;
};

//1st part
class Car:public Vehicle{
public:
    Car(char* model_a, int numDoors_a, int numSits_a, float fuelCapacity_a, float secsTillHundred_a, int yearOfManufacturing_a, char category);
    friend ostream& operator<<(ostream& cout, const Car& car);
private:
    char category;
};

class Bus:public Vehicle{
public:
    Bus(char* model_a, int numDoors_a, int numSits_a, float fuelCapacity_a, float secsTillHundred_a, int yearOfManufacturing_a);
    friend ostream& operator<<(ostream& cout, const Bus& bus);
private:
    char category;
};

Vehicle::Vehicle(char* model_A = "", int numDoors_A = 0, int numWheels_A = 0, int numSits_A = 0,
                float fuelCapacity_A = 0.0, float secsTillHundred_A = 0.0, int yearOfManufacturing_A = 0)
                :model(model_A), numDoors(numDoors_A), numWheels(numWheels_A), numSits(numSits_A), fuelCapacity(fuelCapacity_A), secsTillHundred(secsTillHundred_A), yearOfManufacturing(yearOfManufacturing_A){}

Car::Car(char* model_a, int numDoors_a, int numSits_a, float fuelCapacity_a, float secsTillHundred_a, int yearOfManufacturing_a):Vehicle(model_a, numDoors_a, 4, numSits_a, fuelCapacity_a, secsTillHundred_a, yearOfManufacturing_a), category('C'){}
ostream& operator<<(ostream& cout, Car& car){
    cout<<car.getModel()<<": \n#Doors: "<<car.getNumDoors()<<"\n#Wheels: "<<car.getNumWheels()<<"\n#Sits: "<<car.getNumSits()
                <<"\nCapacity: "<<car.getFuelCapacity()<<"\nSecs Till Hundred: "<<car.getSecsTillHundred()
                <<"\nYear of Manufacturing: "<<car.getYearOfManufacturing()<<"\nRequired Category: "<<car.getCategory()<<endl;
    return cout;
}

Bus::Bus(char* model_a, int numDoors_a, int numSits_a, float fuelCapacity_a, float secsTillHundred_a, int yearOfManufacturing_a):Vehicle(model_a, numDoors_a, 16, numSits_a, fuelCapacity_a, secsTillHundred_a, yearOfManufacturing_a), category('E'){}
ostream& operator<<(ostream& cout, Bus& car){
    cout<<car.getModel()<<": \n#Doors: "<<car.getNumDoors()<<"\n#Wheels: "<<car.getNumWheels()<<"\n#Sits: "<<car.getNumSits()
                <<"\nCapacity: "<<car.getFuelCapacity()<<"\nSecs Till Hundred: "<<car.getSecsTillHundred()
                <<"\nYear of Manufacturing: "<<car.getYearOfManufacturing()<<"\nRequired Category: "<<car.getCategory()<<endl;
    return cout;
}

//2nd part
class CarA{
private:
    VehicleA vehicle;
    char category;
public:
    CarA()
};

class BusA{
private:
    VehicleA vehicle;
    char category;
public:

};


int main()
{

    return 0;
}

