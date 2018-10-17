#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
class Time{
    public:
        Time(int hours, int minutes, int seconds);
        friend ostream& operator<<(ostream& cout, Time time);
        friend istream& operator>>(istream& cin, Time time);
        Time operator+(const Time& time2);
        Time operator-(const Time& time2);
    private:
        int hours;
        int minutes;
        int seconds;
};

Time::Time(int hours = 0, int minutes = 0, int seconds = 0){
    (*this).hours = hours;
    (*this).minutes = minutes;
    (*this).seconds = seconds;
}

Time Time::operator+(const Time& time2){
    int hoursN = (hours + time2.hours) % 24;
    int minutesN = minutes + time2.minutes;
    
    if(minutesN>=60){
        hoursN = (hoursN++ % 24);
        minutesN = minutesN % 60;
    }
    int secondsN = seconds + time2.seconds;
    if(secondsN>=60){
        minutesN++;
        secondsN = secondsN % 60;
        if(minutesN>=60){
            hoursN = (hoursN++) % 24;
            minutesN = minutesN % 60;
        }
    }
    return Time(hoursN, minutesN, secondsN);
}

Time Time::operator-(const Time& time2){
    int hoursN = hours - time2.hours;
    if(hoursN<0)
        hoursN = 24 + hoursN;
    int minutesN = minutes - time2.minutes;
    if(minutesN<0){
        minutesN = 60 + minutesN;
        hoursN--;
    }
    int secondsN = seconds - time2.seconds;
    if(secondsN<0){
        secondsN = 60 + secondsN;
        minutesN--;
        if(minutesN<0){
            minutesN = 60 + minutesN;
            hoursN--;
            if(hoursN<0)
                hoursN = 24 + hoursN;
        }
    }
    return Time(hoursN, minutesN, secondsN);
}

ostream& operator<<(ostream& cout, Time time){
    cout<<"Time is: "<<time.hours<<":"<<time.minutes<<":"<<time.seconds<<endl;
    return cout;
}

/* istream& operator>>(istream& cin, Time time){
    cin>>time.hours>>time.minutes>>time.seconds;
    return cin;
} */

int main(void){
    cout<<"Enter the first time in the format x-x-x :";
    int hours1 = 0;
    int minutes1 = 0;
    int seconds1 = 0;
    if(scanf("%i-%i-%i", &hours1, &minutes1, &seconds1)!=0){
        Time t1(hours1, minutes1, seconds1);
        cout<<"Enter the second time in the format x-x-x :";
        int hours2, minutes2, seconds2;
        if(scanf("%i-%i-%i", &hours2, &minutes2, &seconds2)!=0){
            Time t2(hours2, minutes2, seconds2);

            cout<<t1<<t2;
            cout<<"The addition of time: "<<(t1+t2);
            cout<<"The subtraction of time: "<<(t1-t2);
        }
    }
    return 0;
}