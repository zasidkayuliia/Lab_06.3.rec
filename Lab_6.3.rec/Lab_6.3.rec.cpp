#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>
using namespace std;

// Рекурсивна функція для створення масиву
void Create(int* c, const int size, const int Low, const int High, int i = 0)
{
    c[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(c, size, Low, High, i + 1);
}

// Рекурсивна функція для виведення масиву
void Print(const int* c, const int size, int i = 0)
{
    cout << setw(4) << c[i];
    if (i < size - 1) {
        Print(c, size, i + 1);
    }
    else {
        cout << endl;
    }
}

// Рекурсивна функція для знаходження мінімального елемента масиву
int FindMinElement(const int* c, const int size, int i = 1, int min = INT_MAX)
{
    if (c[i - 1] < min)
        min = c[i - 1];

    if (i == size)
        return min;

    return FindMinElement(c, size, i + 1, min);
}

// Шаблонна рекурсивна функція для створення масиву
template <typename T>
void CreateTemplate(T* c, const int size, const T Low, const T High, int i = 0)
{
    c[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        CreateTemplate(c, size, Low, High, i + 1);
}

// Шаблонна рекурсивна функція для виведення масиву
template <typename T>
void PrintTemplate(const T* c, const int size, int i = 0)
{
    cout << setw(4) << c[i];
    if (i < size - 1) {
        PrintTemplate(c, size, i + 1);
    }
    else {
        cout << endl;
    }
}

// Шаблонна рекурсивна функція для знаходження мінімального елемента масиву
template <typename T>
T FindMinElementTemplate(const T* c, const int size, int i = 1, T min = INT_MAX)
{
    if (c[i - 1] < min)
        min = c[i - 1];

    if (i == size)
        return min;

    return FindMinElementTemplate(c, size, i + 1, min);
}

int main()
{
    SetConsoleOutputCP(1251);
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел

    const int n = 20;
    int c[n]; // Масив для звичайних функцій

    int Low = 1;
    int High = 100;

    // Використання рекурсивних функцій для обробки масиву
    Create(c, n, Low, High);
    Print(c, n);
    int minElement = FindMinElement(c, n);
    cout << "Найменший елемент масиву (звичайні рекурсивні функції): " << minElement << endl;

    // Використання рекурсивних шаблонних функцій для обробки масиву
    int cTemplate[n];
    CreateTemplate<int>(cTemplate, n, Low, High);
    PrintTemplate<int>(cTemplate, n);
    int minElementTemplate = FindMinElementTemplate<int>(cTemplate, n);
    cout << "Найменший елемент масиву (шаблонні рекурсивні функції): " << minElementTemplate << endl;

    return 0;
}