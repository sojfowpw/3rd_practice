#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	vector<string> names; // вектор для названий
	string name;
	while (true) {
		cin >> name; // вводим, пока не будет дана команда остановиться
		if (name == "stop") {
			break;
		}
		names.push_back(name); // заполняем вектор именами
	}
	unordered_map<string, int> amount; // неупорядоченный map, где названию соответствует количество голосов за него
	for (auto& name : names) {
		amount[name]++;
	}
	vector<pair<string, int>> toplist(amount.begin(), amount.end()); // вектор пар для сортировки
	sort(toplist.begin(), toplist.end(), [](const pair<string, int>& a, const pair<string, int>& b) { // сортируем по возрастанию
		return a.second < b.second;
		});
	cout << "Название с наименьшим количеством голосов: " << toplist[0].first << endl;
	sort(toplist.begin(), toplist.end(), [](const pair<string, int>& a, const pair<string, int>& b) { // сортируем по убыванию
		return a.second > b.second;
		});
	cout << "Название с наибольшим количеством голосов: " << toplist[0].first << endl;
	return 0;
}
