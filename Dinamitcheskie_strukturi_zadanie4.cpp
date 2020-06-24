#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include<stdio.h>
#include <string>

using namespace std;

int main(void)
{

	srand(unsigned(time(NULL)));
	setlocale(LC_ALL, "rus");
	string word;
	int i;
	vector<string> v;
	cout << "Сколько слов хотите ввести -" << endl;
	while (!(cin >> i) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено недопустимое значение. Повторите попытку." << endl;
	}
	while (i != 0)
	{
		cout << "Введите слово - " << endl;
		cin >> word;
		v.push_back(word);
		i--;
	}
	bool result;

	vector<string>::iterator iter = v.begin();
	vector<string>::iterator iter_end = v.end();

	cout << "Введённые слова: ";
	for (; iter != iter_end; iter++)
		cout << *iter << " ";

	cout << endl;

	result = is_sorted(v.begin(), v.end());

	if (result == true)
		cout << "Элементы отсортированы" << endl;
	if (result == false)
		cout << "Элементы не отсортированы" << endl;
	return 0;
}
