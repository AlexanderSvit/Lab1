#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

void z1();
void z2();
void z3();
void z4();
void selection_sort(int*, int);
void linearSearch(int*, int);
void(*menu(void))(void);
void delstr(char*, int&, int);
void output(char*);
void name(char*&);
int counter(char* string);

int main() {
	system("chcp 65001");
	void(*funct)(void);
	while (1) {
		system("cls");
		funct = menu();
		if (funct == NULL) {
			cout << "Выход\n";
			break;
		}
		funct();
	}
	system("pause");
	return 0;
}
void(*menu(void))(void) {
	int choice;
	void(*menuOptions[])() = { z1,z2,z3,z4 };
	cout << "1. Задание №2 " << endl << "2. Задание №3" << endl << "3.
		Задание №4" << endl << "4. Задание №5" << endl << "5. Выход";
		cin >> choice;
	if (choice > 0 && choice < 5)
		return menuOptions[choice - 1];
	else return NULL;
}
void z1() {
	char str[] = "input_z1.txt";
	ifstream fin;
	fin.open(str);
	char buff[50];
	fin.getline(buff, 50);
	fin.close();
	int arrSize = strlen(buff) - strlen(buff) / 2;
	while (strchr(buff, ' ') != NULL) {
		char* del = strchr(buff, ' ');
		if (del + 1)strcpy(del, del + 1);
		else del[0] = '\0';
	}
	int intValue = atoi(buff);
	int* arr = new int[arrSize];
	int j = 10;
	for (int i = arrSize - 1; i >= 0; i--) {
		arr[i] = intValue % j;
		intValue /= j;
	}
	ofstream fout;
	fout << " | ";
	selection_sort(arr, arrSize);
	for (int i = 0; i < arrSize; i++) {
		fout << arr[i] << " ";
		cout << arr[i] << " ";
	}
	cout << endl;
	linearSearch(arr, arrSize);
	fout.open(str, ios::app);
	fout << "|";
	for (int i = 0; i < arrSize; i++)
		fout << arr[i] << " ";
	fout.close();
	delete[] arr;
}
void z2() {
	int count = 0, a;
	char* string = new char[100];
	cout << "Введите, сколько нужно удалить строк: ";
	cin >> a;
	count = counter(string);
	cout << "Оставшиеся строки: " << count << endl;
	delstr(string, count, a);
	output(string);
	count = 0;
	delete[] string;
}
void z3() {
	ifstream ifs("input_z4.txt", ios::in);
	ofstream ofs("output_z4.txt", ios::out);
	int i = 0; char* str = new char[256];
	while (ifs.good() && ifs.peek() >= 0)
		str[i++] = ifs.get();
	str[i] = '\0';
	char* word = NULL;
	for (word = strtok(str, " "); word != NULL; word = strtok(NULL, " "))
		if (*word == 'C') ofs << word << " ";
	ifs.close();
	ofs.close();
}
void z4() {
	string s, s2;
	char s1;
	int pos = -1;
	ifstream file("input_z5.txt", ios::in);
	while (!file.eof()) {
		file >> s1;
		s.push_back(s1);
	}
	file.close();
	s2.push_back(s[0]);
	for (int i = 1; i < s.size(); i++) {
		pos = s2.find(s[i]);
		if (pos == -1) s2.push_back(s[i]);
		pos = -1;
	}
	s2.push_back(' ');
	sort(s2.rbegin(), s2.rend());
	ofstream fout("output_z5.txt", ios::trunc);
	fout << s2;
	fout.close();
}
void linearSearch(int* arr, int size) {
	int numb;
	cout << "Введите элемент для поиска: ";
	cin >> numb;
	for (int i = 0; i < size; i++) {
		if (arr[i] == numb) {
			cout << "Элемент находится на " << i + 1 << "-й позиции \n";
			break;
		}
	}
}
void selection_sort(int* arr, int arrSize) {
	int i, j, m, t;
	for (i = 0; i < arrSize; i++) {
		for (j = i, m = i; j < arrSize; j++) {
			if (arr[j] < arr[m])
				m = j;
		}
		t = arr[i];
		arr[i] = arr[m];
		arr[m] = t;
	}
}
int counter(char* string) {
	name(string);
	int count = 0;
	char* str = new char[512];
	ifstream fin;
	fin.open(string);
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла" << endl << endl;
	}
	else {
		while (!fin.eof()) {
			fin.getline(str, 1024, '\n');
			count++;
		}
	}
	fin.close();
	delete[] str;
	return count;
}
void output(char* string) {
	char* str = new char[512];
	ifstream fin;
	fin.open(string);
	if (!fin.is_open()) {
		cout << endl << "Ошибка чтения файла" << endl;
	}
	else {
		while (!fin.eof()) {
			fin.getline(str, 1024);
			cout << str << endl;
		}
		cout << endl;
	}
	fin.close();
	delete[] str;
}
void delstr(char* string, int& count, int number) {
	char* str = new char[512];
	if (count <= number) {
		cout << "Тут не находится столько количество строк" << endl <<
			endl;
	}
	else {
		count -= number;
		ofstream fout;
		fout.open("second.txt");
		ifstream fin;
		fin.open(string);
		if (!fout.is_open() || !fin.is_open()) {
			cout << "Ошибка открытия файла" << endl << endl;
		}
		else {
			for (int i = 0; i < count; i++) {
				fin.getline(str, 1024);
				fout << str << '\n';
			}
		}
		fout.close();
		fin.close();
		fout.open(string);
		fin.open("second.txt");
		if (!fin.is_open() || !fout.is_open()) {
			cout << "Ошибка открытия файла" << endl << endl;
		}
		else {
			while (!fin.eof()) {
				fin.getline(str, 1024);
				fout << str << '\n';
			}
		}
		fout.close();
		fin.close();
	}
	delete[] str;
}
void name(char*& string) {
	cout << "Введите название файла: " << endl;
	cin.ignore();
	cin.getline(string, 100);
}
