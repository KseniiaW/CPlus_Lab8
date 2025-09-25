#ifndef TIME_CLASS_H
#define TIME_CLASS_H

#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time();  
    Time(int h, int m, int s); 

    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }

    void setHours(int h);
    void setMinutes(int m);
    void setSeconds(int s);
    void setTime(int h, int m, int s);

    void print() const;  
    int toSeconds() const; 
    void normalize();  

    Time add(const Time& other) const;  

    bool isValid() const;  
};

Time createTimeFromInput();
void demonstrateTimeClass();

#endif
