#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;
union NumReis {
	int num;
};
union Punkt {
	char punkt[32];
};
union Time {
	time_t time;
};
union Date {
	time_t date;
};
union Cost {
	int cost;
};

struct Avia
{
	union NumReis numReis;
	union Punkt punkt;
	union Time time;
	union Date date;
	union Cost cost;
};
void info(Avia a[], int i) {
	cout << "Number Reis: " << a[i].numReis.num << endl;//Автор
	cout << "Punkt: " << a[i].punkt.punkt << endl;//Название
	cout << "Time: " << a[i].time.time << endl;//Автор
	cout << "Date: " << a[i].date.date << endl;//Название
	cout << "Cost: " << a[i].cost.cost << "$" << endl;//Автор
}
void swapp(Avia& a, Avia& b) {
	Avia temp;
	temp = a;
	a = b;
	b = temp;
}
int main() {
	int k, c, d, n, e, f;
	cout << "Enter the number of reises: ";//Введите количество рейсов
	cin >> n;
	Avia* a = new Avia[n];
	for (;;) {
		cout << "Menu:" << endl;
		cout << "1) Entering an array of structures;" << endl;//Ввод массива структур
		cout << "2) Output array of structures;" << endl;//Вывод массива структур
		cout << "3) Sorting an array of structures;" << endl;//Сортировка массива структур
		cout << "4) Search for an array of structures by a given parameter;" << endl;//Поиск массива структур по заданному параметру
		cout << "5) Change the specified structure;" << endl;//Измение заданной структуры
		cout << "6) Removing a structure from an array;" << endl;//Удаление структуры из массива
		cout << "7) Output." << endl;//Выход
		cout << "Select a menu item: " << endl;//Выберите пункт меню
		cin >> k;
		switch (k) {
		case 1: {
			for (int i = 0; i < n; i++) {
				cout << "Enter number reis\n" << endl;
				cin >> c;
				a[i].numReis.num = c;
				cout << "Enter punkt\n" << endl;
				cin >> a[i].punkt.punkt;
				cout << "Enter times\n" << endl;
				cin >> e;
				a[i].time.time = e;
				cout << "Enter date\n" << endl;
				cin >> d;
				a[i].date.date = d;
				cout << "Enter cost\n" << endl;
				cin >> f;
				a[i].cost.cost = f;
			}
			break;
		}
		case 2: {
			for (int i = 0; i < n; i++) info(a, i);
			break;
		}
		case 3: {
			for (int i = 1; i < n; i++) {
				for (int j = (n - 1); j >= i; j--) {
					for (int k = 0; a[j - 1].numReis.num && k <= n; k++) {
						if (a[j - 1].numReis.num > a[j].numReis.num) {
							swapp(a[j - 1], a[j]);
							break;
						}
						else if (a[j - 1].numReis.num == a[j].numReis.num) continue;
						else break;
					}
				}
			}
			break;
		}
		case 4: {
			int m;
			cout << "1) Number Reis" << endl;
			cout << "2) Punkt" << endl;
			cout << "3) Time" << endl;
			cout << "4) Date" << endl;
			cout << "5) Cost" << endl;
			cout << "Select which parameter to search.: ";//Выберите по какому параметру искать
			cin >> m;
			switch (m) {
			case 1: {
				int b, p = 0;
				cout << "What number reis?" << endl;
				cin >> b;
				for (int i = 0; i < n; i++) {
					if (b == a[i].numReis.num) {
						info(a, i);
						p++;
					}
				}
				if (p == 0)
					cout << "Nothing found for this parameter." << endl;//По данному параметру ничего не найдено
				break;
			}
			case 2: {
				int p = 0;
				char b[32];
				cout << "What punkt?" << endl;;
				cin >> b;
				for (int i = 0; i < n; i++) {
					if (strcmp(b, a[i].punkt.punkt) == 0) {
						info(a, i);
						p++;
					}
				}
				if (p == 0)
					cout << "Nothing found for this parameter." << endl;//По данному параметру ничего не найдено
				break;
			}
			case 3: {
				int p = 0;
				int b;
				cout << "Enter time?";//Введите значение параметра
				cin >> b;
				for (int i = 0; i < n; i++) {
					if (b == a[i].time.time) {
						info(a, i);
						p++;
					}
				}
				if (p == 0)
					cout << "Nothing found for this parameter" << endl;//По данному параметру ничего не найдено
				break;
			}
			case 4: {
				int p = 0;
				int b;
				cout << "Enter date?";//Введите значение параметра
				cin >> b;
				for (int i = 0; i < n; i++) {
					if (b == a[i].date.date) {
						info(a, i);
						p++;
					}
				}
				if (p == 0)
					cout << "Nothing found for this parameter" << endl;//По данному параметру ничего не найдено
				break;
			}

			case 5: {
				int b, p = 0;
				cout << "Enter cost?";//Введите значение параметра
				cin >> b;
				for (int i = 0; i < n; i++) {
					if (b == a[i].cost.cost) {
						info(a, i);
						p++;
					}
				}
				if (p == 0)
					cout << "Nothing found for this parameter" << endl;//По данному параметру ничего не найдено
				break;

			}
				  break;
			}

		case 5: {
			int i;
			cout << "Enter the number of the structure you want change: " << endl;//Введите номер структуры, которую хотите изменить
			cin >> i;
			cout << "Enter number reis\n";
			cin >> c;
			a[i].numReis.num = c;
			cout << "Enter punkt\n";
			cin >> a[i].punkt.punkt;
			cout << "Enter time: ";
			cin >> a[i].time.time;
			cout << "Enter the date: ";
			cin >> a[i].date.date;
			cout << "Enter cost: ";
			cin >> a[i].cost.cost;
			break;
		}
		case 6: {
			int del;
			cout << "Enter the number of the structure you want to delete: " << endl;//Введите номер структуры, которую хотите удалить
			cin >> del;
			Avia* a2 = new Avia[n - 1];
			for (int i = 0; i < n; i++) {
				if (i == del) continue;
				else if (i < del) a2[i] = a[i];
				else a2[i - 1] = a[i];
			}
			delete[] a;
			a = a2;
			n--;
			break;
		}
		case 7: {
			delete[] a;
			return 0;
		}
		default: {
			cout << "Input Error!!!" << endl;//Ошибка ввода
			break;
		}
		}
		}
	}