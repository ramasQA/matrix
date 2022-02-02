#include <cstdlib>
#include <iostream>
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
void timer()
{
   
    for (int i = 0; i < 10; i++)
    {
        cout <<"-"; 
        Sleep(1000);
    }

}


void fillArr(int m[][10], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            m[i][j] = rand() % 20 + 1;
        }
    }
    
}
void printArr(int m[][10], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout.width(4);
            cout << m[i][j];
        }
        cout << endl;
    }
}
void colleftArr(int m[][10], int row, int col)
{
int L;
    cout << "Введите количество сдвигов столбцов влево  ---> "; cin >> L;
   
    for (int k = 0; k < L; k++)
    {

        for (int i = 0; i < row; i++) {
            int tmp = m[i][0];
            for (int j = 0; j < col - 1; j++)
            {
                m[i][j] = m[i][j + 1];

            }
            m[i][col - 1] = tmp;
        }
    }
   
}
void colrigtArr(int m[][10], int row, int col)
{
    int R;
    cout << "Введите количество сдвигов столбцов вправо ---> "; cin >> R;
    
    for (int k = 0; k < R; k++)
    {

        for (int i = 0; i < row; i++)
        {
            int tmp = m[i][col - 1];

            for (int j = col - 1; j >= 0; j--)
            {
                m[i][j] = m[i][j - 1];
            }
            m[i][0] = tmp;
        }
    }
}
void rowleft(int m[][10], int row, int col)
{
    int L;
    cout << "Введите количество сдвигов строк верх ---> "; cin >> L;

    for (int k = 0; k < L; k++)
    {

        for (int i = 0; i < col; i++)
        {
            int tmp = m[0][i];
            for (int j = 0; j < row - 1; j++)
            {
                m[j][i] = m[j + 1][i];

            }
            m[row - 1][i] = tmp;
        }
    }
}
void rowright(int m[][10], int row, int col)
{
    int R;
    cout << "Введите количество сдвигов строк вниз ---> "; cin >> R;
    
    for (int k = 0; k < R; k++)
    {

        for (int i = 0; i < col; i++)
        {
            int tmp = m[row - 1][i];
            for (int j = row - 1; j >= 0; j--)
            {
                m[j][i] = m[j - 1][i];

            }
            m[0][i] = tmp;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");
    system("chcp 1251");
    system("cls");
    system("color F0");
    srand(time(NULL));
    const int row = 5;
    const int col = 10;
    int arr[row][col];
    
    int sel = 0; int count = 3;
    for (; ; )
    {

        do
        {
            cout << "Что будем делать? \n"
                << "1. Сдвигать стобцы.\n"
                << "2. Сдвигать строки.\n"
                << "3. Ничего не смотреть, поверить и так поставить оценку)))\n";


            cout << "---> "; cin >> sel;
            if (sel == 1 || sel == 2)
                cout << "Не доверяете ?, ну чтож продолжим программу...\n";
            if (sel > 2 && sel != 3) {
                cout << "Как можно запутаться в цифрах 1 или 2 :), попробуйте еще раз.\n";
                count--;
                cout << "У вас осталось - " << count << " попыток.";
                if (count == 0) {
                    cout << "Программа будт закрыта...\n";
                    exit(0);
                }
                continue;

            }

            if (sel == 3) {
                cout << "Мудрый выбор, спасибо за доверие!\n";
                cout << "Оценка будет выбрана генератором случайных чисел\n";
                int xx = rand() % 2 + 10;
                cout << "Итоговая оценка"; timer(); cout << xx << endl;
                system("pause");
                exit(0);
            }

        } while (sel > 3);

        switch (sel)
        {
        case 1:
            cout << "Для проверки выводим наш массив.\n";
            fillArr(arr, row, col);
            printArr(arr, row, col);
            int sel2;
            cout << "Выбрано сдвиг столбцов !\n";
            cout << "В какую сторону сдивгать: \n"
                << "1. Влево.\n"
                << "2. Вправо.\n";
            cout << "--->"; cin >> sel2;

            switch (sel2)
            {
            case 1:
                colleftArr(arr, row, col);
                cout << "Матрица со сдвигом влево по столбцам\n";
                printArr(arr, row, col);
                break;
            case 2:
                colrigtArr(arr, row, col);
                cout << "Матрица со сдвигом вправо по столбцам\n";
                printArr(arr, row, col);
                break;
            default:
                cout << "Ошибка!\n";
                continue;
            }
        case 2:
            cout << "Для проверки выводим наш массив.\n";
                fillArr(arr, row, col);
                printArr(arr, row, col);
            int sel3;
            cout << "Выбрано сдвиг строк !\n";
            cout << "В какую сторону сдивгать: \n"
                << "1. Вверх.\n"
                << "2. Ввниз.\n";
            cout << "--->"; cin >> sel3;

            switch (sel3)
            {
            case 1:
                rowleft(arr, row, col);
                cout << "Матрица со сдвигом вверх по строкам\n";
                printArr(arr, row, col);
                break;
            case 2:
                rowright(arr, row, col);
                cout << "Матрица со сдвигом ввниз по строкам\n";
                printArr(arr, row, col);
                break;
            default:
                cout << "Ошибка!\n";
                break;
            }
            break;
        default:
            cout << "Ошибка!\n";
            continue;
        }
        system("pause");
        system("cls");
        int zz;
        cout << "Для повторного запуска программы нажмите 1. \n";
        cout << "Для выхода из программы нажмите 0. \n";
            cout << "---> "; cin >> zz;
        if (zz == 0) exit(0);
        else continue;

    }
}

