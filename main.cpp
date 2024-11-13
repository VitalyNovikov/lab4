#include <iostream>
#include <cmath>
using namespace std;

// Декларація функцій
void Proc3();
void Boolean13();
void Integer8();
void Menu();
bool isPositiveInput(int &A, int &B, int &C);
bool isTwoDigitInput(int &num);

// Головна функція
int main() {
    Menu(); // Запуск меню вибору задач
    return 0;
}

// Функція меню вибору завдань
void Menu() {
    int choice;
    cout << "\nВиберіть задачу для виконання або 0 для виходу:\n";
    cout << "1 - Proc3 (обчислення середніх значень для пар чисел)\n";
    cout << "2 - Boolean13 (перевірка, чи хоча б одне з трьох чисел додатне)\n";
    cout << "3 - Integer8 (перестановка цифр двозначного числа)\n";
    cout << "0 - Завершити програму\n";
    cout << "Ваш вибір: ";
    cin >> choice;

    switch (choice) {
        case 1:
            Proc3(); // Виклик функції Proc3
            Menu(); // Рекурсивний виклик для повторного меню
            break;
        case 2:
            Boolean13(); // Виклик функції Boolean13
            Menu(); // Рекурсивний виклик для повторного меню
            break;
        case 3:
            Integer8(); // Виклик функції Integer8
            Menu(); // Рекурсивний виклик для повторного меню
            break;
        case 0:
            cout << "Програма завершена." << endl;
            break;
        default:
            cout << "Помилка: невірний вибір. Спробуйте ще раз.\n";
            Menu(); // Повторний виклик меню при неправильному вводі
            break;
    }
}

// Функція для обчислення середнього арифметичного та геометричного для пар (A, B), (A, C), (A, D)
void Proc3() {
    double A, B, C, D;
    cout << "\nВведіть чотири числа (A, B, C, D) для обчислення середніх значень: ";
    cin >> A >> B >> C >> D;

    double AMean, GMean;

    // Пара (A, B)
    AMean = (A + B) / 2;
    GMean = sqrt(A * B);
    cout << "Середнє арифметичне для (A, B): " << AMean << endl;
    cout << "Середнє геометричне для (A, B): " << GMean << endl;

    // Пара (A, C)
    AMean = (A + C) / 2;
    GMean = sqrt(A * C);
    cout << "Середнє арифметичне для (A, C): " << AMean << endl;
    cout << "Середнє геометричне для (A, C): " << GMean << endl;

    // Пара (A, D)
    AMean = (A + D) / 2;
    GMean = sqrt(A * D);
    cout << "Середнє арифметичне для (A, D): " << AMean << endl;
    cout << "Середнє геометричне для (A, D): " << GMean << endl;
}

// Функція для перевірки, чи хоча б одне з трьох чисел A, B, C додатне
void Boolean13() {
    int A, B, C;

    // Перевірка вводу
    if (!isPositiveInput(A, B, C)) {
        cout << "Помилка: введіть додатні числа.\n";
        return; // Завершити виконання, якщо введені числа некоректні
    }

    // Обчислення
    bool result = (A > 0 || B > 0 || C > 0);

    // Виведення результату
    if (result) {
        cout << "Принаймні одне число додатне.\n";
    } else {
        cout << "Жодне з чисел не є додатним.\n";
    }
}

// Функція для перестановки цифр двозначного числа
void Integer8() {
    int num;

    // Перевірка вводу
    if (!isTwoDigitInput(num)) {
        cout << "Помилка: введене число не є двозначним.\n";
        return; // Завершити виконання, якщо число не є двозначним
    }

    int tens = num / 10;           // десятки
    int units = num % 10;          // одиниці
    int swapped = units * 10 + tens; // нове число з переставленими цифрами

    cout << "Число після перестановки цифр: " << swapped << endl;
}

// Функція для перевірки коректності введення для чисел A, B, C
bool isPositiveInput(int &A, int &B, int &C) {
    cout << "\nВведіть три числа (A, B, C): ";
    cin >> A >> B >> C;
    return (A > 0 && B > 0 && C > 0); // Перевірка на додатні числа
}

// Функція для перевірки коректності введення для двозначного числа
bool isTwoDigitInput(int &num) {
    cout << "\nВведіть двозначне число: ";
    cin >> num;
    return (num >= 10 && num <= 99); // Перевірка на двозначність
}
