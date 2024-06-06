#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "Windows.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    cout << "Введите количество студентов, пришедших на пару: ";
    int N; // количество студентов
    cin >> N;
    cout << "Введите критическое время: ";
    int crittime; // критическое время
    cin >> crittime;
    cin.ignore(); // удаление символа новой строки из потока для дальнейшего ввода
    string student; // информация про студента
    cout << "Студенты: ";
    vector<pair<string, int>> students; // вектор всех студентов
    for (int i = 0; i < N; i++) {
        getline(cin, student); // ввод информации
        istringstream iss(student); // создание объекта, который используется для разбора строки - команды
        string lastname;
        int time;
        if (iss >> lastname >> time) {
            students.emplace_back(lastname, time); // заполняем пару
        }
    }
    sort(students.begin(), students.end(), [](const auto& a, const auto& b) { // сортируем пару по возрастанию
        return a.second < b.second;
        });
    auto it = upper_bound(students.begin(), students.end(), pair<string, int>("", crittime), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second; // ищем первый элемент, который больше критического времени
        });
    cout << "Не прошедшие проверку: " << endl;
    for (; it != students.end(); ++it) { // вывод студентов, не прошедших проверку
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
