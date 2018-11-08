#include <iostream>

using namespace std;

class Vehicle{
public:
    Vehicle(char* model_A, int numDoors_A,
            int numWheels_A, int numSits_A,
            float fuelCapacity_A, float secsTillHundred_A, 
            int yearOfManufacturing_A);

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
    Car(char* model_a, int numDoors_a, int numSits_a,
        float fuelCapacity_a, 
        float secsTillHundred_a,
        int yearOfManufacturing_a);

    friend ostream& operator<<(ostream& cout, const Car& car);
    char getCategory(){
        return category;
    }
private:
    char category;
};

class Bus:public Vehicle{
public:
    Bus(char* model_a, int numDoors_a, int numSits_a, float fuelCapacity_a, float secsTillHundred_a, int yearOfManufacturing_a);
    friend ostream& operator<<(ostream& cout, const Bus& bus);
    char getCategory(){
        return category;
    }
    void openDoors(){
        cout<<"Doors opened"<<endl;
    }
    void closeDoors(){
        cout<<"Doors closed"<<endl;
    }
private:
    char category;
};

Vehicle::Vehicle(char* model_A = NULL, int numDoors_A = 0, int numWheels_A = 0, int numSits_A = 0,
                float fuelCapacity_A = 0.0, float secsTillHundred_A = 0.0, int yearOfManufacturing_A = 0):model(model_A), numDoors(numDoors_A), numWheels(numWheels_A), numSits(numSits_A), fuelCapacity(fuelCapacity_A), secsTillHundred(secsTillHundred_A), yearOfManufacturing(yearOfManufacturing_A){}

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
    Vehicle* vehicle;
    char category;
public:
    CarA(char* model_a, int numDoors_a, int numSits_a, 
         float fuelCapacity_a, float secsTillHundred_a, 
         int yearOfManufacturing_a);
    friend ostream& operator<<(ostream& cout, const Car& car);
    char getCategory(){
        return category;
    }
    Vehicle getVehicle(){
        return *vehicle;
    }
};

ostream& operator<<(ostream& cout, CarA& car){
    Vehicle carThis = car.getVehicle();
    cout<<carThis.getModel()<<": \n#Doors: "<<carThis.getNumDoors()<<"\n#Wheels: "<<carThis.getNumWheels()<<"\n#Sits: "<<carThis.getNumSits()
                <<"\nCapacity: "<<carThis.getFuelCapacity()<<"\nSecs Till Hundred: "<<carThis.getSecsTillHundred()
                <<"\nYear of Manufacturing: "<<carThis.getYearOfManufacturing()<<"\nRequired Category: "<<car.getCategory()<<endl;
    return cout;
}

class BusA{
private:
    Vehicle* vehicle;
    char category;
public:
    BusA(char* model_a, int numDoors_a, int numSits_a, float fuelCapacity_a, float secsTillHundred_a, int yearOfManufacturing_a);
    friend ostream& operator<<(ostream& cout, const BusA& bus);
    char getCategory(){
        return category;
    }
    void openDoors(){
        cout<<"Doors opened"<<endl;
    }
    void closeDoors(){
        cout<<"Doors closed"<<endl;
    }
    Vehicle getVehicle(){
        return *vehicle;
    }
};

CarA::CarA(char* model_a, int numDoors_a, int numSits_a, float fuelCapacity_a, float secsTillHundred_a, int yearOfManufacturing_a):category('C'){
    vehicle = new Vehicle(model_a, numDoors_a, 4, numSits_a, fuelCapacity_a, secsTillHundred_a, yearOfManufacturing_a);
    category = 'C';
}

BusA::BusA(char* model_a, int numDoors_a, int numSits_a, float fuelCapacity_a, float secsTillHundred_a, int yearOfManufacturing_a):category('E'){
    vehicle = new Vehicle(model_a, numDoors_a, 16, numSits_a, fuelCapacity_a, secsTillHundred_a, yearOfManufacturing_a);
    category = 'E';
}
ostream& operator<<(ostream& cout, BusA& bus){
    Vehicle busThis = bus.getVehicle();
    cout<<busThis.getModel()<<": \n#Doors: "<<busThis.getNumDoors()<<"\n#Wheels: "<<busThis.getNumWheels()<<"\n#Sits: "<<busThis.getNumSits()
                <<"\nCapacity: "<<busThis.getFuelCapacity()<<"\nSecs Till Hundred: "<<busThis.getSecsTillHundred()
                <<"\nYear of Manufacturing: "<<busThis.getYearOfManufacturing()<<"\nRequired Category: "<<bus.getCategory()<<endl;
    return cout;
}

int main(void)
{
    char modelBuf[256];
    char modelBuf2[256];
    char modelBuf3[256];
    char modelBuf4[256];
    Bus* bus;
    Car* car;
    BusA* busA;
    CarA* carA;
    int numDoors_a = 0;
    int numSits_a = 0; 
    float fuelCapacity_a = 0.0;
    float secsTillHundred_a = 0.0;
    int yearOfManufacturing_a = 0;

    printf("Enter the model of the Car: ");
    if(scanf("%s", modelBuf)!=-1){
        printf("Enter in the following order numDoors, numSits, fuelCapacity, secsTillHundred, yearOfManufacturing: ");
        if(scanf("%i,%i,%f,%f,%i", &numDoors_a, &numSits_a, &fuelCapacity_a, &secsTillHundred_a, &yearOfManufacturing_a)!=-1){
            if(numDoors_a<=0 || numSits_a<=0 || fuelCapacity_a<=0.0 || secsTillHundred_a<=0.0 || yearOfManufacturing_a<=0){
                cout<<"Wrong data for Car";
                return 1;
            }
            car = new Car(modelBuf, numDoors_a, numSits_a, fuelCapacity_a, secsTillHundred_a, yearOfManufacturing_a);    
            cout<<(*car)<<endl;
        }else{
            cout<<"Wrong data for Car";
            return 1;
        }
    }
    numDoors_a = 0;
    numSits_a = 0; 
    fuelCapacity_a = 0.0;
    secsTillHundred_a = 0.0;
    yearOfManufacturing_a = 0;
    printf("Enter the model of the Bus: ");
    if(scanf("%s", modelBuf2)!=-1){
        printf("Enter in the following order numDoors, numSits, fuelCapacity, secsTillHundred, yearOfManufacturing: ");
        if(scanf("%i,%i,%f,%f,%i", &numDoors_a, &numSits_a, &fuelCapacity_a, &secsTillHundred_a, &yearOfManufacturing_a)!=-1){
            if(numDoors_a<=0 || numSits_a<=0 || fuelCapacity_a<=0.0 || secsTillHundred_a<=0.0 || yearOfManufacturing_a<=0){
                cout<<"Wrong data for Bus";
                return 1;
            }
            bus = new Bus(modelBuf2, numDoors_a, numSits_a, fuelCapacity_a, secsTillHundred_a, yearOfManufacturing_a);
        }else{
            cout<<"Wrong data for Bus";
            return 1;
        }
    }
    
    printf("Enter the model of the CarA: ");
    if(scanf("%s", modelBuf3)!=-1){
        printf("Enter in the following order numDoors, numSits, fuelCapacity, secsTillHundred, yearOfManufacturing: ");
        if(scanf("%i,%i,%f,%f,%i", &numDoors_a, &numSits_a, &fuelCapacity_a, &secsTillHundred_a, &yearOfManufacturing_a)!=-1){
            if(numDoors_a<=0 || numSits_a<=0 || fuelCapacity_a<=0.0 || secsTillHundred_a<=0.0 || yearOfManufacturing_a<=0){
                cout<<"Wrong data for CarA";
                return 1;
            }
            carA = new CarA(modelBuf3, numDoors_a, numSits_a, fuelCapacity_a, secsTillHundred_a, yearOfManufacturing_a);
        }else{
            cout<<"Wrong data for CarA";
            return 1;
        }
    }

    printf("Enter the model of the BusA: ");
    if(scanf("%s", modelBuf4)!=-1){
        printf("Enter in the following order numDoors, numSits, fuelCapacity, secsTillHundred, yearOfManufacturing: ");
        if(scanf("%i,%i,%f,%f,%i", &numDoors_a, &numSits_a, &fuelCapacity_a, &secsTillHundred_a, &yearOfManufacturing_a)!=-1){
            if(numDoors_a<=0 || numSits_a<=0 || fuelCapacity_a<=0.0 || secsTillHundred_a<=0.0 || yearOfManufacturing_a<=0){
                cout<<"Wrong data for BusA";
                return 1;
            }
            busA = new BusA(modelBuf4, numDoors_a, numSits_a, fuelCapacity_a, secsTillHundred_a, yearOfManufacturing_a);
        }else{
            cout<<"Wrong data for BusA";
            return 1;
        }
    }

    cout<<"Car: "<<(*car)<<endl;
    cout<<"Bus: "<<(*bus)<<endl;
    (*bus).openDoors();
    (*bus).closeDoors();
    cout<<"CarA: "<<(*carA)<<endl;
    cout<<"BusA: "<<(*busA)<<endl;
    (*busA).openDoors();
    (*busA).openDoors();
    return 0;
}