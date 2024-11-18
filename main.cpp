#include <iostream>
#include <cmath>
using namespace std;

// Декларація функцій
void Proc3();
void Boolean13();
void Integer8();
void showMenu();
bool isPositiveInput(int &A, int &B, int &C);
bool isTwoDigitInput(int &num);
void Mean(double X, double Y, double &AMean, double &GMean); // Декларація функції для обчислення середніх значень
void checkBoolean13(int A, int B, int C, bool &result);      // Перевірка для Boolean13
void checkInteger8(int num, int &swapped);                  // Перевірка для Integer8
void printBoolean13Result(bool result);
void printInteger8Result(int swapped);
bool isInRange(int num); // Перевірка діапазону [-100, 100]

// Головна функція
int main() {
    showMenu(); // Запуск меню вибору задач
    return 0;
}

// Функція меню вибору завдань
void showMenu() {
    int choice;
    do {
        cout << "\nВиберіть задачу для виконання або 0 для виходу:\n";
        cout << "1 - Proc3 (обчислення середніх значень для пар чисел)\n";
        cout << "2 - Boolean13 (перевірка, чи хоча б одне з трьох чисел додатне)\n";
        cout << "3 - Integer8 (перестановка цифр двозначного числа)\n";
        cout << "0 - Завершити програму\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Proc3();
                break;
            case 2:
                Boolean13();
                break;
            case 3:
                Integer8();
                break;
            case 0:
                cout << "Програма завершена." << endl;
                break;
            default:
                cout << "Помилка: невірний вибір. Спробуйте ще раз.\n";
                break;
        }
    } while (choice != 0);
}

// Функція для обчислення середнього арифметичного та геометричного для пар (A, B), (A, C), (A, D)
void Proc3() {
    double A, B, C, D;
    cout << "\nВведіть чотири числа (A, B, C, D) в діапазоні [-100, 100]: ";
    cin >> A >> B >> C >> D;

    if (!isInRange(A) || !isInRange(B) || !isInRange(C) || !isInRange(D)) {
        cout << "Помилка: всі числа мають бути в межах [-100, 100].\n";
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

    // Перевірка вводу
    if (!isPositiveInput(A, B, C)) {
        cout << "Помилка: всі числа мають бути в межах [-100, 100] і додатними.\n";
        return; // Завершити виконання, якщо введені числа некоректні
    }

    bool result;
    checkBoolean13(A, B, C, result); // Виклик функції для перевірки
    printBoolean13Result(result);    // Викликаємо функцію для виведення результату
}

// Функція для перестановки цифр двозначного числа
void Integer8() {
    int num;

    // Перевірка вводу
    if (!isTwoDigitInput(num)) {
        cout << "Помилка: введене число не є двозначним або не в межах [-100, 100].\n";
        return; // Завершити виконання, якщо число не є двозначним
    }

    int swapped;
    checkInteger8(num, swapped); // Виклик функції для перестановки цифр
    printInteger8Result(swapped); // Викликаємо функцію для виведення результату
}

// Функція для обчислення середнього арифметичного та геометричного
void Mean(double X, double Y, double &AMean, double &GMean) {
    AMean = (X + Y) / 2; // обчислення середнього арифметичного
    GMean = sqrt(abs(X * Y));  // обчислення середнього геометричного
}

// Функція для перевірки коректності введення для чисел A, B, C
bool isPositiveInput(int &A, int &B, int &C) {
    cout << "\nВведіть три числа (A, B, C): ";
    cin >> A >> B >> C;
    return (isInRange(A) && isInRange(B) && isInRange(C) && A > 0 && B > 0 && C > 0);
}

// Функція для перевірки коректності введення для двозначного числа
bool isTwoDigitInput(int &num) {
    cout << "\nВведіть двозначне число: ";
    cin >> num;
    return (isInRange(num) && num >= 10 && num <= 99);
}

// Функція для перевірки, чи число в межах [-100, 100]
bool isInRange(int num) {
    return num >= -100 && num <= 100;
}

// Функція для перевірки, чи хоча б одне з чисел додатне
void checkBoolean13(int A, int B, int C, bool &result) {
    result = (A > 0 || B > 0 || C > 0); // Обчислення результату
}

// Функція для перестановки цифр двозначного числа
void checkInteger8(int num, int &swapped) {
    int tens = num / 10;         // десятки
    int units = num % 10;        // одиниці
    swapped = units * 10 + tens; // нове число з переставленими цифрами
}

// Функція для виведення результату перевірки, чи хоча б одне з трьох чисел додатне
void printBoolean13Result(bool result) {
    cout << (result ? "Принаймні одне число додатне.\n" : "Жодне з чисел не є додатним.\n");
}

// Функція для виведення результату перестановки цифр двозначного числа
void printInteger8Result(int swapped) {
    cout << "Число після перестановки цифр: " << swapped << endl;
}
