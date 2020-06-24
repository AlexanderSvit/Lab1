#include <iostream>
#include <fstream>
using namespace std;
void createMatrix(char path[], int);
void showMatrix(char path[], int, int, int);
void changeMatrix(char path1[], char path2[], int, int, int, int);

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	int n, m, l, k;
	char path1[] = "D:\\matrix1.bin";
	char path2[] = "D:\\matrix2.bin";
	cout << "Введите размерность матриц n*m: ";
	cin >> n >> m;
	cout << "Введите кол-во матриц в файлах: ";
	cin >> k >> l;
	createMatrix(path1, n * m * k);
	createMatrix(path2, n * m * l);
	cout << "Исходные файлы:\n";
	showMatrix(path1, n, m, k);
	cout << '\n' << "----------------------------------" << '\n';
	showMatrix(path2, n, m, l);
	changeMatrix(path1, path2, n, m, k, l);
	cout << "\nИзмененные файлы:\n";
	showMatrix(path1, n, m, k);
	cout << '\n' << "----------------------------------" << '\n';
	showMatrix(path2, n, m, l);
	cout << '\n';
	system("pause");
	return 0;
}

void createMatrix(char path[], int size) {
	int* matr = new int[size];
	cout << "Введите матрицы:\n";
	for (int i = 0; i < size; i++)
		cin >> matr[i];
	ofstream file(path, ios::binary | ios::trunc);
	file.write((char*)matr, size * sizeof(int));
	file.close();
	delete[] matr;
}

void showMatrix(char path[], int n, int m, int k) {
	int row = 0, clmn = 0;
	int* matr = new int[k * n * m];
	ifstream file(path, ios::binary);
	file.read((char*)matr, k * n * m * sizeof(int));
	file.close();
	for (int i = 0; i < k * n * m; i++) {
		if (row == m) {
			row = 0;
			cout << '\n';
			clmn++;
		}
		if (clmn == n) {
			cout << '\n';
			row = 0; clmn = 0;
		}
		cout << matr[i] << " ";
		row++;
	}
	delete[] matr;
}

void changeMatrix(char path1[], char path2[], int n, int m, int k, int l) {
	int min, temp, count = 1;
	int* matr1 = new int[k * n * m];
	int* matr2 = new int[l * n * m];
	ifstream file1(path1, ios::binary);
	file1.read((char*)matr1, k * n * m * sizeof(int));
	file1.close();
	ifstream file2(path2, ios::binary);
	file2.read((char*)matr2, l * n * m * sizeof(int));
	file2.close();
	k* n* m < l* n* m ? min = k * n * m : min = l * n * m;
	for (int i = 0; i < min; i += m * n) {
		if (count % 2) {
			for (int j = i; j < i + m * n; j++) {
				temp = matr1[j];
				matr1[j] = matr2[j];
				matr2[j] = temp;
			}
			count++;
		}
		else count++;
	}
	ofstream file3(path1, ios::binary | ios::trunc);
	file3.write((char*)matr1, k * m * n * sizeof(int));
	file3.close();
	ofstream file4(path2, ios::binary | ios::trunc);
	file4.write((char*)matr2, l * m * n * sizeof(int));
	file4.close();
	delete[] matr1;
	delete[] matr2;
}
