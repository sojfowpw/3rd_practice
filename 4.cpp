#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите строку: ";
	string str; // строка
	getline(cin, str);
	str.erase(remove_if(str.begin(), str.end(), ::ispunct), str.end()); // удаляем знаки препинания
	str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end()); // удаляем пробелы
	transform(str.begin(), str.end(), str.begin(), ::tolower); // переводим в нижний регистр
	string reversestr(str.rbegin(), str.rend()); // создаём обратную строку
	double amount = inner_product(str.begin(), str.end(), reversestr.begin(), 0, plus<>(), equal_to<>()); // equal_to - сравнение символов, plus - сложение
	cout << "Строка палиндром на " << amount / reversestr.size() * 100.0 << " %.";
	return 0;
}
