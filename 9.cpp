#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int main() {
	random_device rd;
	mt19937_64 random_(rd());
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество чисел: ";
	int N; // количество чисел
	cin >> N;
	vector<int> digits; // вектор чисел
	cout << "Исходный вектор: ";
	for (int i = 0; i < N; i++) { // заполняем вектор случайными значениями
		digits.push_back(random_() % (201) - 100);
		cout << digits[i] << " ";
	}
	cout << endl << "Введите позицию k: ";
	int k; // позиция
	cin >> k; 
	k -= 1; // вычитаем 1 для удобства: позиции будем считать с 1
	nth_element(digits.begin(), digits.begin() + k, digits.end()); // сортируем
	cout << "k-ая порядковая статистика: " << digits[k];
	return 0;
}
