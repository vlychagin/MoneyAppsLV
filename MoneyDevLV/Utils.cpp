#include "stdafx.h"
#include "Utils.h"

void init()
{
	system("color 1f");
	SetConsoleOutputCP(1251); // ����� � ��������� 1251
	SetConsoleCP(1251);       // ����  � ��������� 1251
	srand(GetTickCount());    // "��������" ���������� ��������� �����

	// ��������� ������ ������ � cout
	// boolalpha - �������� ���������� ���������� � ���� true/false ������ 1/0
	// fixed � setprecision(2) - �������������� ��������� ��������, ���
	// ������� �������� (float, double) ������� � ������������� ������� � �����
	// ������� � ������� ����� (����� �������)
	cout << boolalpha << fixed << setprecision(2);
} // init

// �������� ������� �� ����� �������  
void waitForKey(char *text)
{
	cout << text;
	int key = _getch();
	if (key == 0 || key == 224) key = _getch();
} // waitForKey


int Rand(int Lo, int Hi)
{
	return Lo + rand() % (Hi - Lo + 1);
} // Rand

double Rand(double Lo, double Hi)
{
	return Lo + (Hi - Lo) * rand() / (RAND_MAX + 1);
} // Rand

