#include <iostream>
#include <cmath>
using namespace std;

// Процедура обчислення середнього арифметичного та геометричного двох чисел
void Mean(double X, double Y, double &AMean, double &GMean) {
    AMean = (X + Y) / 2;        // обчислення середнього арифметичного
    GMean = sqrt(X * Y);         // обчислення середнього геометричного
}

// Функція для обчислення середнього арифметичного та геометричного для пар (A, B), (A, C), (A, D)
void Proc3(double A, double B, double C, double D) {
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
bool Boolean13(int A, int B, int C) {
    return (A > 0 || B > 0 || C > 0); // перевірка, чи хоча б одне число додатне
}

// Функція для перестановки цифр двозначного числа
int Integer8(int number) {
    if (number < 10 || number > 99) { // перевірка, що число двозначне
        cout << "Помилка: введене число не є двозначним." << endl;
        return -1; // ознака помилки
    }
    int tens = number / 10;           // десятки
    int units = number % 10;          // одиниці
    return units * 10 + tens;         // нове число з переставленими цифрами
}

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
        case 1: {
            double A, B, C, D;
            cout << "\nВведіть чотири числа (A, B, C, D) для обчислення середніх значень: ";
            cin >> A >> B >> C >> D;
            Proc3(A, B, C, D);
            Menu(); // Рекурсивний виклик для повторного відображення меню
            break;
        }
        case 2: {
            int A, B, C;
            cout << "\nВведіть три цілі числа (A, B, C) для перевірки: ";
            cin >> A >> B >> C;
            if (Boolean13(A, B, C)) {
                cout << "Принаймні одне число додатне.\n";
            } else {
                cout << "Жодне з чисел не є додатним.\n";
            }
            Menu(); // Рекурсивний виклик для повторного відображення меню
            break;
        }
        case 3: {
            int num;
            cout << "\nВведіть двозначне число для перестановки цифр: ";
            cin >> num;
            int swapped = Integer8(num);
            if (swapped != -1) {
                cout << "Число після перестановки цифр: " << swapped << endl;
            }
            Menu(); // Рекурсивний виклик для повторного відображення меню
            break;
        }
        case 0:
            cout << "Програма завершена." << endl;
            break;
        default:
            cout << "Помилка: невірний вибір. Спробуйте ще раз.\n";
            Menu(); // Повторний виклик меню при неправильному вводі
            break;
    }
}

int main() {
    Menu(); // Запускаємо меню вибору задач
    return 0;
}
