#include <iostream>
#include <locale>
#include <iomanip>
#include <string>
#include <Windows.h> 
#include <fstream>
#include <sstream>
#define TESTING

using namespace std;

#pragma pack(push, 1)

struct Note
{
	string secondname;
	string name;
	int phonenum;
	int date[3];
};

#pragma pack(pop)

void Create(char* filename, Note* n, int N);
void ADD(char* filename, Note* n, int N);
void Print(char* filename);
void Search(char* filename, char* secondname);

#ifdef TESTING

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char filename[100];
	char secondname[100];
	Note* n;
	int N;
	int menuItem;

	cout << "Введіть ім\'я файлу: "; cin >> filename;

	do {
		cout << endl << endl;
		cout << "\t[1] - створити список" << endl;
		cout << "\t[2] - переглянути список" << endl;
		cout << "\t[3] - поповнити список" << endl;
		cout << "\t[4] - пошук інформації за прізвищем" << endl;
		cout << "\t[0] - Exit" << endl;
		cout << "ваш вибір: "; cin >> menuItem;
		cout << endl << endl;

		switch (menuItem)
		{
		case 1:
			cout << "Введіть кількість компонентів у списку: "; cin >> N;
			n = new Note[N];
			Create(filename, n, N);
			delete[] n;
			break;
		case 2:
			Print(filename);
			break;
		case 3:
			cout << "Введіть кількість нових компонентів у списку: "; cin >> N;
			n = new Note[N];
			ADD(filename, n, N);
			delete[] n;
			break;
		case 4:
			cout << "Введіть прізвище для пошуку: "; cin >> secondname;
			Search(filename, secondname);
			break;
		case 0:
			break;
		default:
			cout << "Невірно введене значення!\n" << "Повторіть спробу." << endl;
		}
	} while (menuItem != 0);

	system("pause");
	return 0;
}
#endif

void Create(char* filename, Note* n, int N)
{
	ofstream fout(filename);

	fout << "=================================================================" << endl
		 << "| № |   Прізвище   |  Ім\'я  | Номер телефону | День народження  |" << endl
		 << "-----------------------------------------------------------------" << endl;

	for (int i = 0; i < N; i++)
	{
		cout << "Людина № " << i + 1 << ":" << endl;

		cin.get();
		cin.sync();

		cout << "Прізвище: "; getline(cin, n[i].secondname);
		cout << "Ім\'я: "; getline(cin, n[i].name);
		cout << "Номер телефону: +380"; cin >> n[i].phonenum;
		cout << "День народження: "; cin >> n[i].date[0];
		cout << "Місяць народження: "; cin >> n[i].date[1];
		cout << "Рік народження: "; cin >> n[i].date[2];
		cout << endl;

		fout << "| " << setw(1) << right << i + 1 << " ";
		fout << "| " << setw(12) << left << n[i].secondname << " ";
		fout << "| " << setw(6) << right << n[i].name << " ";
		fout << "| +380" << setw(10) << left << n[i].phonenum << " ";
		fout << "| " << setw(5) << right << n[i].date[0] << "." << n[i].date[1] << "."
			 << n[i].date[2] << "     |" << endl;
	}
	fout << "=================================================================" << endl;
}

void ADD(char* filename, Note* n, int N)
{
	ofstream fout(filename, ios::app);

	for (int i = 0; i < N; i++)
	{
		cout << "Людина № " << i + 1 << ":" << endl;

		cin.get();
		cin.sync();

		cout << "Прізвище: "; getline(cin, n[i].secondname);
		cout << "Ім\'я: "; getline(cin, n[i].name);
		cout << "Номер телефону: +380"; cin >> n[i].phonenum;
		cout << "День народження: "; cin >> n[i].date[0];
		cout << "Місяць народження: "; cin >> n[i].date[1];
		cout << "Рік народження: "; cin >> n[i].date[2];
		cout << endl;

		fout << "| " << setw(1) << right << i + 1 << " ";
		fout << "| " << setw(12) << left << n[i].secondname << " ";
		fout << "| " << setw(6) << right << n[i].name << " ";
		fout << "| +380" << setw(10) << left << n[i].phonenum << " ";
		fout << "| " << setw(5) << right << n[i].date[0] << "." << n[i].date[1] << "."
			<< n[i].date[2] << "     |" << endl;
	}
	fout << "=================================================================" << endl;
}

void Print(char* filename)
{
	ifstream fin(filename);

	string s;

	while (getline(fin, s))
	{
		cout << s << endl;
	}
}

void Search(char* filename, char* secondname)
{
	ifstream fin(filename);

	string s;
	int k = 0;

	cout << "=================================================================" << endl
		<< "| № |   Прізвище   |  Ім\'я  | Номер телефону | День народження  |" << endl
		<< "-----------------------------------------------------------------" << endl;

	while (getline(fin, s))
	{
		if (s.find(secondname, 0) != -1)
		{
			cout << s << endl;
			k++;
		}
	}

	if (k == 0)
	{
		cout << "Інформацію про людину не знайдено" << endl;
	}
	cout << "=================================================================" << endl;
}