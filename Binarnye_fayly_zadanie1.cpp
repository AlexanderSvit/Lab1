#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;
union clases {
	int clasNum;
	char clasChar[5];
};
enum behaviors { bad = 1, good, best };
struct students {
	char name[30];
	union clases clas;
	unsigned number;
	enum behaviors behavior;
};

int checkInt();
void writeToFile(students*, char path[], int);
students* readFromFile(char path[], int&);
void createFile(char path[]);
void showFile(char path[]);
void addToFile(char path[]);
void delFromFile(char path[]);
void sort(char path[]);
void(*menu(void))(char*);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char choice, buff[50];
	char path[50] = "D:\\students.bin";
	cout << "Текущий путь: " << path;
	cout << "\nЖелаете изменить?: y/n: ";
	cin >> choice;
	if (choice == 'y') {
		cout << "Введите новый путь:\n";
		cin.ignore();
		cin.getline(path, 50);
		cout << "Новый путь: " << path << '\n';
		system("pause");
	}
	void(*funct)(char path[]);
	while (1) {
		system("cls");
		funct = menu();
		if (funct == NULL) {
			cout << "Выход\n";
			break;
		}
		funct(path);
	}
	return 0;
}

void(*menu(void))(char path[]) {
	int choice;
	void(*menuOptions[])(char path[]) = { createFile, addToFile, showFile, delFromFile, sort };
	cout << "1.Создание файла \n2.Добавление элемента в конец файла \n3.Вывод содержимого файла на экран \n4.Удаление элемента из файла \n5.Сортировка\n6.Выход\n";
	cin >> choice;
	if (choice > 0 && choice < 6)
		return menuOptions[choice - 1];
	else return NULL;
}

int checkInt() {
	bool exit = true;
	unsigned buff;
	do {
		cin >> buff;
		if (!(exit = cin.good())) {
			cout << "Значение введено неверно. Повторите ввод\n";
			cin.clear();
			cin.ignore(30, '\n');
		}
	} while (!exit);
	return buff;
}

void createFile(char path[]) {
	int buff, count;
	cout << "Введите количество школьников" << '\n';
	count = checkInt();
	students* student = new students[count];
	for (int i = 0; i < count; i++) {
		system("cls");
		cout << "------Вводим данные------" << '\n';
		cout << "Студент " << i + 1 << '\n';
		cout << "Введите ФИО школьника" << '\n';
		cin.ignore();
		cin.getline(student[i].name, 30);
		cout << "Введите класс студента" << '\n';
		buff = checkInt(); student[i].clas.clasNum = buff;
		cout << "Введите номер школьника" << '\n';
		buff = checkInt(); student[i].number = buff;
		cout << "Оцените поведение школьника:\n1.Неудовлетворительно\n2.Удовлетворительно.\n3.Примерно\n";
		do { buff = checkInt(); } while ((buff < 1) || (buff > 3));
		student[i].behavior = (behaviors)buff;
		cin.ignore();
	}
	writeToFile(student, path, count);
	delete[] student;
}
void addToFile(char path[]) {
	int buff;
	students* student = new students[1];
	cout << "Добавление студента:\n";
	cout << "------Вводим данные------" << '\n';
	cout << "Введите ФИО студента" << '\n';
	cin.ignore();
	cin.getline(student[0].name, 30);
	cout << "Введите класс студента" << '\n';
	buff = checkInt(); student[0].clas.clasNum = buff;
	cout << "Введите номер телефона" << '\n';
	buff = checkInt(); student[0].number = buff;
	cout << "Оцените поведение студента:\n1.Неудовлетворительно\n2.Удовлетворительно.\n3.Примерно\n";
	do { buff = checkInt(); } while ((buff < 1) || (buff > 3));
	student[0].behavior = (behaviors)buff;
	cin.ignore();
	int count;
	ifstream file(path, ios::binary);
	file.read((char*)&count, sizeof(count));
	count++;
	students* stdnt = new students[count];
	file.read((char*)stdnt, count * sizeof(students));
	file.close();
	stdnt[count - 1] = student[0];
	writeToFile(stdnt, path, count);
	delete[] student;
	delete[] stdnt;
}
void showFile(char path[]) {
	int count;
	students* student = readFromFile(path, count);
	for (int i = 0; i < count; i++) {
		cout << "Студент " << i + 1 << '\n';
		cout << "ФИО " << student[i].name << '\n';
		cout << "Класс " << student[i].clas.clasNum << '\n';
		cout << "Номер " << student[i].number << '\n';
		if (student[i].behavior == 1) cout << "Поведение: Неудовлетворительно\n";
		else if (student[i].behavior == 2) cout << "Поведение: Удовлетворительно\n";
		else cout << "Поведение: Примерно\n";
	}
	cout << '\n';
	delete[] student;
	system("pause");
}
void delFromFile(char path[]) {
	int choice, count;
	cout << "Введите номер школьника, запись которого необходимо удалить\n";
	cin >> choice;
	students* student = readFromFile(path, count);
	if (count == 1)cout << "Удаляется последняя запись!\n";
	system("pause");
	choice--;
	for (choice; choice < count; choice++) {
		student[choice] = student[choice + 1];
	}
	count--;
	writeToFile(student, path, count);
	delete[] student;
}

void sort(char path[]) {
	system("cls");
	cout << "------Сортируем данные------" << '\n';
	int count;
	students* student = readFromFile(path, count);
	students temp;
	int leftMark = 1;
	int rightMark = count - 1;
	while (leftMark <= rightMark) {
		for (int i = leftMark; i <= rightMark; i++)
			if (strcmp(student[i].name, student[i - 1].name) < 0) {
				temp = student[i];
				student[i] = student[i - 1];
				student[i - 1] = temp;
			}
		rightMark--;
		for (int i = rightMark; i >= leftMark; i--)
			if (strcmp(student[i].name, student[i - 1].name) < 0) {
				temp = student[i];
				student[i] = student[i - 1];
				student[i - 1] = temp;
			}
		leftMark++;
	}
	writeToFile(student, path, count);
	delete[] student;
	cout << "Данные отсортрованы" << '\n';
	system("pause");
}
void writeToFile(students* student, char path[], int count) {
	ofstream file_bin(path, ios::binary | ios::trunc);
	file_bin.write((char*)&count, sizeof(count));
	file_bin.write((char*)student, count * sizeof(students));
	file_bin.close();
}
students* readFromFile(char path[], int& count) {
	ifstream file(path, ios::binary);
	file.read((char*)&count, sizeof(count));
	students* student = new students[count];
	file.read((char*)student, count * sizeof(students));
	file.close();
	return student;
}
