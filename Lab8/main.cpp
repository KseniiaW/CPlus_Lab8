#include <iostream>
#include "time_class.h"

using namespace std;

void demonstrateAssignmentRequirements() {
    cout << "=== ВЫПОЛНЕНИЕ ЗАДАНИЯ ===" << endl;

    const Time time1(11, 59, 59); 
    const Time time2(1, 70, 80);   

    Time time3;

    cout << "Инициализированные объекты:" << endl;
    cout << "time1: ";
    time1.print();
    cout << endl;

    cout << "time2: ";
    time2.print();
    cout << " (демонстрация нормализации)" << endl;

    cout << "time3 (неинициализированный): ";
    time3.print();
    cout << endl;

    cout << "\nСложение time1 и time2:" << endl;
    time3 = time1.add(time2);

    cout << "time1 + time2 = ";
    time3.print();
    cout << endl;


    cout << "\nРезультат присвоен третьему объекту:" << endl;
    cout << "time3: ";
    time3.print();
    cout << " (" << time3.toSeconds() << " секунд)" << endl;
}

void showMenu() {
    cout << "\n=== КЛАСС TIME ===" << endl;
    cout << "1 - Демонстрация требований задания" << endl;
    cout << "2 - Полная демонстрация класса" << endl;
    cout << "3 - Интерактивный режим" << endl;
    cout << "0 - Выход" << endl;
    cout << "Выберите действие: ";
}

void interactiveMode() {
    cout << "\n=== ИНТЕРАКТИВНЫЙ РЕЖИМ ===" << endl;

    Time t1 = createTimeFromInput();
    cout << "Первое время: ";
    t1.print();
    cout << endl;

    Time t2 = createTimeFromInput();
    cout << "Второе время: ";
    t2.print();
    cout << endl;

    Time sum = t1.add(t2);
    cout << "Сумма: ";
    sum.print();
    cout << " (" << sum.toSeconds() << " секунд)" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            demonstrateAssignmentRequirements();
            break;

        case 2:
            demonstrateTimeClass();
            break;

        case 3:
            interactiveMode();
            break;

        case 0:
            cout << "Выход из программы..." << endl;
            break;

        default:
            cout << "Неверный выбор! Попробуйте снова." << endl;
            break;
        }

        if (choice != 0) {
            cout << "\nНажмите Enter для продолжения...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 0);

    return 0;
}