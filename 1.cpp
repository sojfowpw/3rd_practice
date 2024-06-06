#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите высоту автобуса (в см): ";
	int height; // высота автобуса
	cin >> height;
	cout << "Введите количество туннелей: ";
	int N; // количество туннелей
	cin >> N;
	vector<int> tunnels; // вектор высот туннелей
	cout << "Введите высоту " << N << " туннелей (в см): ";
	int tunnel; // высота туннеля
	for (int i = 0; i < N; i++) {
		cin >> tunnel; // ввод и заполнение вектора
		tunnels.push_back(tunnel);
	}
	auto crash_it = find_if(tunnels.begin(), tunnels.end(), [height](const int& tunnel_height) { // поиск итератора, указывающего на туннель, который вызовет аварию
		return (tunnel_height - height) < 10; // лямда-функция проверяет будет ли между автобусом и туннелем расстояние хотя бы 10 см
		});
	if (crash_it != tunnels.end()) { // если итератор найден, авария произошла
		cout << "Автобус врезался в " << crash_it - tunnels.begin() + 1 << " туннель высотой " << *crash_it << " см.";
	}
	else { 
		cout << "Аварии удалось избежать.";
	}
	return 0;
}
