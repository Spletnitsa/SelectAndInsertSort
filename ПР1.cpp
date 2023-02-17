#include <iostream>
using namespace std;

void SelSort(int* arr, int e)
{
	int C = 0, M = 0, sw;
	for (int i = 0; i < e - 1; i++) {
		for (int j = i + 1; j < e; j++) {
			if (arr[i] > arr[j]) {
				C++;
				sw = arr[i];
				arr[i] = arr[j];
				arr[j] = sw;
				M++;
			}
		}
	}
	cout << "сравнения: " << C << "; перестановки: " << M << endl;
}

void InsSort(int* arr, int e) {
	int C = 0, M = 0;
	for (int j = 1; j < e; ++j) {
		int key = arr[j];
		int i = j - 1;
		while (i >= 0 && arr[i] > key) {
			C++;
			arr[i + 1] = arr[i];
			M++;
			i--;
		}
		arr[i + 1] = key;
	}
	cout << "сравнения: " << C << "; перестановки: " << M << endl;
}

void WorstSelSort(int* arr, int e)
{
	int sv;
	for (int i = 0; i < e - 1; i++) {
		for (int j = i + 1; j < e; j++) {
			if (arr[i] < arr[j]) {
				sv = arr[i];
				arr[i] = arr[j];
				arr[j] = sv;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int q;
	int Myarr[10];
	cout << "Мещеряков Андрей ИКБО-15-19" << endl;
	cout << "Практическая работа №1 сравнение простых алгоритмов сортировки массивов" << endl;
	cout << "ввод массива в ручную (1)/автоматический ввод массива (2): ";
	cin >> q;
	if (q == 1) {
		int qt;
		cout << "введите массив:";
		for (int i = 0; i < 10; i++)
		{
			cout << "[" << i << "]= ";
			cin >> Myarr[i];
		}
		cout << "сортровка выбором(1)/сортировка вставками(2): ";
		cin >> qt;
		if (qt == 1){
			cout << "сортировка выбором: ";
			SelSort(Myarr, 10);
		}
		else if (qt == 2) {
			cout << "сортировка вставками: ";
			InsSort(Myarr, 10);
		}
	}
	else if (q == 2) {
		int q_2, e, s, m = 37;
		cout << "сортровка выбором(1)/сортировка вставками(2): ";
		cin >> q_2;
		for ( e = 10000; e <= 50000; e += 10000) {
			s = e;
			int* Autoarr = new int[e];
			for (int i = 0; i < e; i++) {
				s = (m * s + i) % e;
				Autoarr[i] = s;
			}
			switch (q_2) {
			case 1:
				cout << "---------------------------\n";
				cout << "сортировка выбором n= " << e << endl;
				cout << "* средний случай" << endl;
				SelSort(Autoarr, e);
				cout << "* наилучший случай" << endl;
				SelSort(Autoarr, e);
				cout << "* наихудший случай" << endl;
				WorstSelSort(Autoarr, e);
				SelSort(Autoarr, e);
				break;
			case 2:
				cout << "---------------------------\n";
				cout << "сортировка вставками n= " << e << endl;
				cout << "* средний случай" << endl;
				InsSort(Autoarr, e);
				cout << "* наилучший случай" << endl;
				InsSort(Autoarr, e);
				cout << "* наихудший случай" << endl;
				WorstSelSort(Autoarr, e);
				InsSort(Autoarr, e);
				break;
			}
		}
	}
}