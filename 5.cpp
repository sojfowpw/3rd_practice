#include <iostream>
#include <vector>
#include <random>

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
	for (int i = 0; i < N; i++) {
		digits.push_back(random_() % 101); // заполняем вектор случайными числами
		cout << digits[i] << " "; // вывод исходного вектора
	}
	cout << endl;
	vector<int> reversedig(digits.rbegin(), digits.rend()); // создаём обратную копию вектора
	for (int i = 1; i < N; i += 2) {
		digits[i] = reversedig[i]; // если позиция числа чётная, меняем число
	}
	cout << "Новый вектор: ";
	for (auto& digit : digits) { // вывод нового вектора
		cout << digit << " ";
	}
	return 0;
}
