#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>

using namespace std;

bool isPrime(int digit) { // проверка числа на простоту
	if (digit == 1 || digit % 2 == 0) {
		return false;
	}
	else if (digit <= 3) {
		return true;
	}
	else {
		for (int i = 5; i <= sqrt(digit); i += 2) {
			if (digit % i == 0) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	random_device rd;
	mt19937_64 random_(rd());
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество чисел: ";
	int N; // количество чисел
	cin >> N;
	vector<int> digits; // вектор чисел
	cout << "Исходный контейнер: ";
	for (int i = 0; i < N; i++) {
		digits.push_back(random_() % (100) + 1); // заполнение случайными значениями
		cout << digits[i] << " ";
	}
	cout << endl;
	vector<int> prime_digits; // вектор простых чисел
	copy_if(digits.begin(), digits.end(), back_inserter(prime_digits), isPrime); // копируем в новый вектор только простые числа
	double sum = accumulate(prime_digits.begin(), prime_digits.end(), 0); // считаем сумму всех простых чисел
	cout << "Среднее арифметическое: " << sum / prime_digits.size(); // выводим среднее арифметическое значение
	return 0;
}
