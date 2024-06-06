#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include "Windows.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    cout << "Введите количество студентов: ";
    int N; // количество студентов
    cin >> N;
    cin.ignore(); // удаление символа новой строки из потока для дальнейшего ввода
    vector<pair<string, int>> students; // вектор всех студентов
    string student; // информация про студента
    cout << "Студенты: ";
    for (int i = 0; i < N; i++) {
        getline(cin, student); // ввод информации
        istringstream iss(student); // создание объекта, который используется для разбора строки - команды
        string lastname;
        int time;
        if (iss >> lastname >> time) {
            students.emplace_back(lastname, time); // заполняем пару
        }
    }
    cout << "Введите количество баллов для зачёта: ";
    double credit; // баллы для зачёта
    cin >> credit;
    cout << "Студенты, получившие зачёт: ";
    for_each(students.begin(), students.end(), [credit](const pair<string, int>& student) { // для каждого лямбда-функция
        if (student.second >= credit) { // если баллы больше зачётного количества, то студент получил зачёт
            cout << student.first << " ";
        }
        });
    auto it = lower_bound(students.begin(), students.end(), pair<string, int>("", credit), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second; // итератор на наименьший элемент, который либо равен, либо больше зачётного значения
        });
    if (it != students.begin()) {
        --it; // итератор на элемент, меньше зачётного значения
        cout << "\nСтудент, которого пощадили: " << it->first;
    }
    else {
        cout << "\nВсе студенты получили зачёт.";
    }
    return 0;
}
