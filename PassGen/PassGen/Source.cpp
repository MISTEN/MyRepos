#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <ctime>
#pragma warning(disable : 4996)

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	char allsymbols[] = "abcdefghijklmnopqrstuvwxyzABCDIFGHIJKLMNOPQRSTUVWXYZ0123456789";
	string pass, resouse;
	int passlen, randnum;

	ofstream pass_file;

	pass_file.open("��������������� ������.txt");

	cout << "������� ����� �������� � ������ " << endl;
	cin >> passlen;

//	cout << "����� ������ �������� ������������ ([�]��, ������ [�]����, ������ [�]����" << endl;
//	cin >> passlen;

	cout << "������� ��� �������" << endl;
	cin >> resouse;

	srand(time(NULL));
//-----------------------------------------------------------
	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	pass_file << asctime(timeinfo) << "\n";
//----------------------------------------------------------
	pass_file << resouse << "\t";
	
	for (int i = 1; i <= passlen; i++)
	{
		randnum = rand() % 62 + 1;

		pass_file << allsymbols[randnum];
	}

	pass_file << "\n--------------------------------------";
	return 0;
}