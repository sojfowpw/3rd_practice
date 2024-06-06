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
	for (int i = 0; i < N; i++) {
		digits.push_back(random_() % (101) - 50); // заполняем вектор случайными значениями
	}
	for (auto& digit : digits) {
		cout << digit << " "; // вывод исходного вектора
	}
	cout << endl;
	while (digits.size() > 2) {
		auto min_it = min_element(digits.begin(), digits.end()); // итератор минимального значения
		digits.erase(min_it); // удаляем минимальное
		auto max_it = max_element(digits.begin(), digits.end()); // итератор максимального значения
		digits.erase(max_it); // удаляем максимальное
	}
	if (digits.size() == 1) {
		cout << "Среднее сгенерированное число: " << digits[0];
	}
	else {
		cout << "Среднее сгенерированное число: " << ((double) digits[1] + digits[0]) / 2;
	}
	return 0;
}
