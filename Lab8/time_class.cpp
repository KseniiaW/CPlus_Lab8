#include <iostream>
#include <iomanip>
#include "time_class.h"

using namespace std;

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    normalize();
}

void Time::normalize() {
    if (seconds >= 60 || seconds < 0) {
        minutes += seconds / 60;
        seconds = seconds % 60;
        if (seconds < 0) {
            seconds += 60;
            minutes--;
        }
    }

    if (minutes >= 60 || minutes < 0) {
        hours += minutes / 60;
        minutes = minutes % 60;
        if (minutes < 0) {
            minutes += 60;
            hours--;
        }
    }

    if (hours < 0) {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
}

void Time::setHours(int h) {
    hours = h;
    normalize();
}

void Time::setMinutes(int m) {
    minutes = m;
    normalize();
}

void Time::setSeconds(int s) {
    seconds = s;
    normalize();
}

void Time::setTime(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;
    normalize();
}

void Time::print() const {
    cout << setw(2) << setfill('0') << hours << ":"
        << setw(2) << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << seconds;
}

int Time::toSeconds() const {
    return hours * 3600 + minutes * 60 + seconds;
}

Time Time::add(const Time& other) const {
    Time result;
    result.hours = hours + other.hours;
    result.minutes = minutes + other.minutes;
    result.seconds = seconds + other.seconds;
    result.normalize();
    return result;
}

bool Time::isValid() const {
    return (hours >= 0 && minutes >= 0 && minutes < 60 &&
        seconds >= 0 && seconds < 60);
}

Time createTimeFromInput() {
    int h, m, s;

    cout << "������� �����:" << endl;
    cout << "����: ";
    cin >> h;
    cout << "������: ";
    cin >> m;
    cout << "�������: ";
    cin >> s;

    return Time(h, m, s);
}

void demonstrateTimeClass() {
    cout << "\n=== ������������ ������ ������ TIME ===" << endl;

    // �������� �������� ������� ���������
    cout << "\n1. �������� ��������:" << endl;

    const Time time1(2, 45, 30); 
    const Time time2(1, 70, 90);  


    Time time3;

    cout << "time1 (�����������): ";
    time1.print();
    cout << endl;

    cout << "time2 (�����������, � �������������): ";
    time2.print();
    cout << " (�������: 01:70:90)" << endl;

    cout << "time3 (��������������������): ";
    time3.print();
    cout << endl;

    cout << "\n2. ������������ ������������:" << endl;

    Time test1(0, 125, 130); 
    cout << "Time(0, 125, 130) -> ";
    test1.print();
    cout << endl;

    Time test2(25, 70, 90);  
    cout << "Time(25, 70, 90) -> ";
    test2.print();
    cout << endl;

    Time test3(10, 45, 130); 
    cout << "Time(10, 45, 130) -> ";
    test3.print();
    cout << endl;


    cout << "\n3. �������� ������:" << endl;

    cout << "time1: ";
    time1.print();
    cout << " (" << time1.toSeconds() << " ������)" << endl;

    cout << "time2: ";
    time2.print();
    cout << " (" << time2.toSeconds() << " ������)" << endl;

    time3 = time1.add(time2);

    cout << "time3 = time1 + time2: ";
    time3.print();
    cout << " (" << time3.toSeconds() << " ������)" << endl;

    cout << "\n4. �������������� �������:" << endl;

    Time t4(12, 30, 45);
    Time t5(13, 45, 20);
    Time t6 = t4.add(t5);

    cout << "t4: ";
    t4.print();
    cout << " + t5: ";
    t5.print();
    cout << " = t6: ";
    t6.print();
    cout << endl;

    cout << "\n5. ������ � ���������������� ������:" << endl;

    Time userTime = createTimeFromInput();
    cout << "��������� �����: ";
    userTime.print();
    cout << " (" << userTime.toSeconds() << " ������)" << endl;

    cout << "\n6. �������� ������������ �������:" << endl;
    cout << "time1 ���������: " << (time1.isValid() ? "��" : "���") << endl;
    cout << "time2 ���������: " << (time2.isValid() ? "��" : "���") << endl;

    Time invalid(-1, 70, -10);
    cout << "invalid time: ";
    invalid.print();
    cout << " ���������: " << (invalid.isValid() ? "��" : "���") << endl;
}