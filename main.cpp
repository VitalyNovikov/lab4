#include <iostream>
#include <cmath>
using namespace std;

// Декларація функцій
void Proc3();
void Boolean13();
void Integer8();
void showMenu();
bool isValidInputProc3(double &A, double &B, double &C, double &D); // Функція для перевірки правильності введення для Proc3
bool isPositiveInput(int &A, int &B, int &C); // Функція для перевірки на додатні числа для Boolean13
bool isTwoDigitInput(int &num); // Функція для перевірки двозначного числа для Integer8
void Mean(double X, double Y, double &AMean, double &GMean); // Декларація функції для обчислення середніх значень
void checkBoolean13(int A, int B, int C);
void checkInteger8(int num);

// Головна функція
int main() {
    showMenu(); // Запуск меню вибору задач
    return 0;
}

// Функція меню вибору завдань
void showMenu() {
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
            showMenu(); // Рекурсивний виклик для повторного меню
            break;
        case 2:
            Boolean13(); // Виклик функції Boolean13
            showMenu(); // Рекурсивний виклик для повторного меню
            break;
        case 3:
            Integer8(); // Виклик функції Integer8
            showMenu(); // Рекурсивний виклик для повторного меню
            break;
        case 0:
            cout << "Програма завершена." << endl;
            break;
        default:
            cout << "Помилка: невірний вибір. Спробуйте ще раз.\n";
            showMenu(); // Повторний виклик меню при неправильному вводі
            break;
    }
}

// Функція для обчислення середнього арифметичного та геометричного для пар (A, B), (A, C), (A, D)
void Proc3() {
    double A, B, C, D;

    // Перевірка введених значень для Proc3
    if (!isValidInputProc3(A, B, C, D)) {
        cout << "Некоректне введення. Повертаємося в меню.\n";
        showMenu(); // Повертаємось в меню, якщо введено некоректно
        return;
    }

    double AMean, GMean;

    // Пара (A, B)
    Mean(A, B, AMean, GMean);
    cout << "Середнє арифметичне для (A, B): " << AMean << endl;
    cout << "Середнє геометричне для (A, B): " << GMean << endl;

    // Пара (A, C)
    Mean(A, C, AMean, GMean);
    cout << "Середнє арифметичне для (A, C): " << AMean << endl;
    cout << "Середнє геометричне для (A, C): " << GMean << endl;

    // Пара (A, D)
    Mean(A, D, AMean, GMean);
    cout << "Середнє арифметичне для (A, D): " << AMean << endl;
    cout << "Середнє геометричне для (A, D): " << GMean << endl;
}

// Функція для перевірки, чи хоча б одне з трьох чисел A, B, C додатне
void Boolean13() {
    int A, B, C;

    // Перевірка вводу для Boolean13
    if (!isPositiveInput(A, B, C)) {
        cout << "Некоректне введення. Повертаємося в меню.\n";
        showMenu(); // Повертаємось в меню, якщо введено некоректно
        return;
    }

    checkBoolean13(A, B, C); // Викликаємо функцію для обчислення та виведення результату
}

// Функція для перестановки цифр двозначного числа
void Integer8() {
    int num;

    // Перевірка вводу для Integer8
    if (!isTwoDigitInput(num)) {
        cout << "Некоректне введення. Повертаємося в меню.\n";
        showMenu(); // Повертаємось в меню, якщо число не двозначне
        return;
    }

    checkInteger8(num); // Викликаємо функцію для обчислення перестановки цифр
}

// Функція для обчислення середнього арифметичного та геометричного
void Mean(double X, double Y, double &AMean, double &GMean) {
    AMean = (X + Y) / 2; // обчислення середнього арифметичного
    GMean = sqrt(X * Y);  // обчислення середнього геометричного
}

// Функція для перевірки правильності введення для Proc3 (A, B, C, D)
bool isValidInputProc3(double &A, double &B, double &C, double &D) {
    cout << "\nВведіть чотири числа (A, B, C, D): ";
    cin >> A >> B >> C >> D;
    return (cin.good()); // Перевірка, чи всі введені значення є числами
}

// Функція для перевірки правильності введення для чисел A, B, C (додатні)
bool isPositiveInput(int &A, int &B, int &C) {
    cout << "\nВведіть три числа (A, B, C): ";
    cin >> A >> B >> C;
    return (A > 0 && B > 0 && C > 0); // Перевірка на додатні числа
}

// Функція для перевірки введення двозначного числа
bool isTwoDigitInput(int &num) {
    cout << "\nВведіть двозначне число: ";
    cin >> num;
    return (num >= 10 && num <= 99); // Перевірка на двозначність
}

// Функція для перевірки, чи хоча б одне з трьох чисел додатне
void checkBoolean13(int A, int B, int C) {
    bool result = (A > 0 || B > 0 || C > 0); // Обчислення результату

    // Виведення результату
    if (result) {
        cout << "Принаймні одне число додатне.\n";
    } else {
        cout << "Жодне з чисел не є додатним.\n";
    }
}

// Функція для перестановки цифр двозначного числа
void checkInteger8(int num) {
    int tens = num / 10;           // десятки
    int units = num % 10;          // одиниці
    int swapped = units * 10 + tens; // нове число з переставленими цифрами

    cout << "Число після перестановки цифр: " << swapped << endl;
}
