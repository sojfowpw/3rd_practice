#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int binaryDegree(int digit) { // перевод числа в двоичную степень
	int dig = 1, result = 0; // dig - разряд числа
	while (digit) {
		result += digit % 2 * dig;
		digit /= 2;
		dig *= 10;
	}
	return result;
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите число: ";
	int digit; // число в десятичной системе счисления
	cin >> digit;
	string ranges = to_string(binaryDegree(digit)); // число в двоичной системе счисления
	cout << "Двоичная запись числа: " << ranges << endl;
	ranges.erase(unique(ranges.begin(), ranges.end()), ranges.end()); // удаляем повторяющиеся 0 и 1
	int one = count(ranges.begin(), ranges.end(), '1'); // количество 1
	int zero = count(ranges.begin(), ranges.end(), '0'); // количество 0
	cout << "Количество диапазонов нулей: " << zero << "\nКоличество диапазонов единиц: " << one;
	return 0;
}
