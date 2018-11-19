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

class TwoWheelsVehicles:public virtual Vehicle{
    public:
        TwoWheelsVehicles(int weight_a, int manYear_a):Vehicle(weight_a, manYear_a),wheels(2){}
    private:
        int wheels;
};

class NoEngineVehicles:public virtual Vehicle{
    public:
        NoEngineVehicles(int weight_a, int manYear_a):Vehicle(weight_a, manYear_a){
            engineModel = (char*) malloc(sizeof(char)*5);
            engineModel[0]='N';
            engineModel[1]='o';
            engineModel[2]='n';
            engineModel[3]='e';
            engineModel[4]='\0';
        }
        char* getEngine(){
            return engineModel;
        }
    private:
        char* engineModel;
};

class Bicycle:public NoEngineVehicles, public TwoWheelsVehicles{
    public:
        Bicycle(int weight_a, int manYear_a, int maxWeight_a, int numSpeeds_a = 0): 
            NoEngineVehicles(weight_a, manYear_a), TwoWheelsVehicles(weight_a, manYear_a), 
            Vehicle(weight_a, manYear_a),maxWeight(maxWeight_a),numSpeeds(numSpeeds_a){}
        friend ostream& operator<<(ostream& cout, Bicycle& bicycle);
    private:
        int maxWeight;
        int numSpeeds;
};

ostream& operator<<(ostream& cout, Bicycle& bicycle){
    cout<<"Bicycle\n"
        <<"Weight: "<<bicycle.getWeight()<<"\n"
        <<"Year: "<<bicycle.getManYear()<<"\n"
        <<"Engine: "<<bicycle.getEngine()<<"\n"
        <<"Endures weight: "<<bicycle.maxWeight<<"\n"
        <<"Speeds number: "<<bicycle.numSpeeds;
}

int main(void){
    int weight;
    int year;
    int maxWeight;
    int numSpeeds;
    Bicycle* bicycle;
    printf("Enter the values for the bicycle (weight, year, max weight, speeds number): ");
    if(scanf("%i,%i,%i,%i", &weight, &year, &maxWeight, &numSpeeds)!=-1){
        if(weight<0 || year<0 || maxWeight<0 || numSpeeds<0){
            printf("Enter correct values");
            return 1;
        }
        bicycle = new Bicycle(weight,year,maxWeight,numSpeeds);
        cout<<*bicycle<<endl;
    }
    return 0;
}