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



int main()
{
    setlocale(LC_ALL, "");
    system("chcp 1251");
    system("cls");
    system("color F0");
    srand(time(NULL));
   
    cout << "Введите 5 фамилий студентов! \n";
    string *s = new string [256]; //создаем динамический массим типа стринг

    for (int i = 0; i < 5; i++) { //создаем цикл на 5 элементов
        cout<< "Family # " << i + 1 <<" ";
        cin >> s[i];
    }
    cout << "\nНачальний список студентов: \n";
    
    for (int i = 0; i < 5; i++) { //выводим наш массив строк
        cout << "# " <<i+1 <<"- " <<s[i] << "\n";
    }
    
    cout << "\nСортированный список студентов: \n";
    for (int i = 0; i < 5; i++) { //обычная пузырьковая сортировка, начинамем с нулевого элемента
        for (int j = i + 1; j < 5; j++) { //второй цикл начинаем с первого элемента

            if (s[i] > s[j]) { //сравниваем эелементы на предмет больше
                string ct = s[i]; //создаем временную строку, куда записываем нулевой элемент
                s[i] = s[j];
                s[j] = ct;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << "# " << i + 1 << "- " << s[i] << "\n";
    }
        system("pause");
}

