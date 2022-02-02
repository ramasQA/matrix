#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cctype>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>    
#include <ctime> 
#include <time.h>
using namespace std;


void fillArray(int** pArr, int row, int col) //функция инициализации динамического массива
{
    for (int i = 0; i < row; i++) {
        pArr[i] = new int[col]; //выделяем память под количество столбцов
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            pArr[i][j] = rand() % 50 + 1; //заполняем массим рандомными числами
        }

    }
}
void prnArray(int** pArr, int row, int col) // Функция печати массива
{
    cout << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << setw(3) << pArr[i][j] << "  "; //печать с интервалом 3
        }
        cout << endl;
    }

    cout << endl;
}
int** trnArray(int** pArr, int row, int col) //функция транспонирования массива
{
    int** t_pArr = new int* [col]; //выделяем память под новый массив, но только по столбцам
    for (int i = 0; i < col; i++)
        t_pArr[i] = new int[row]; //а элементам выделяем память по строкам, то есть обратный порядок
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            t_pArr[j][i] = pArr[i][j]; //перезаписываем переворачивая в другой массив
        }
    }
    return t_pArr; //возвращем указатель на новый массив
}

int main()
{
    setlocale(LC_ALL, "");
    system("chcp 1251");
    system("cls");
    system("color F0");
    srand(time(NULL));
    int row; int col;
    cout << "Введите количество строк (row) "; cin >> row;
    cout << "Введите количество столбцов (col) "; cin >> col;
    int** pArr = new int* [row]; //выделяем память под количество строк

    fillArray(pArr, row, col);
    cout << "========Start Array==============";
    prnArray(pArr, row, col);
    pArr = trnArray(pArr, row, col); //присваиваем первому массиву уже перевернутый

    cout << "========Trans Array==============";

    prnArray(pArr, col, row); //а при печати второго массива передаем в функцю в обратном порядке столбцы и строки

    system("pause");
}

