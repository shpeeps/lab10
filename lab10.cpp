#include<iostream>
#include <Windows.h>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void message(string msg, string user, int N) {
	SYSTEMTIME t;
	GetLocalTime(&t);
	ofstream fout("log.txt", ofstream::app); // открываем лог-файл
	fout << t.wDay << "." << t.wMonth << "." << t.wYear << "   " << t.wHour << ":" << t.wMinute << ":" << t.wSecond << "   " << user << msg << N << endl; // заполняем лог-файл
	fout.close(); // закрываем лог-файл
};

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string user;
	string msg;

	cout << "Введите имя пользователя ";
	cin >> user;

	int N;
	cout << "Введите количество бочонков ";
	cin >> N;
	
	msg = " ввел(а) количество бочонков: ";
	message(msg, user, N);
	cout << "Нажмите любую клавишу, чтобы узнать номер следующего вытянутого бочонка " << endl;
	
	vector<int> vectorx(N);
	for (size_t i = 0; i < N; ++i) {
		vectorx[i] = i + 1;
	}
	for (int i = 0; i < N; ++i) {
		swap(vectorx[i], vectorx[std::rand() % N]);
	}
	for (size_t i = 0; i < N; ++i) {
		cout << vectorx[i] << endl;
		system("pause");
		msg = "  вытянул(а) бочонок из заданного количества: ";
		message(msg, user, N);
	}
}
