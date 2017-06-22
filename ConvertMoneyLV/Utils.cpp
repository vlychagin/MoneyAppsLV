#include "stdafx.h"
#include "Utils.h"

void init()
{
	system("color 1f");
	SetConsoleOutputCP(1251); // вывод в кодировке 1251
	SetConsoleCP(1251);       // ввод  в кодировке 1251
	srand(GetTickCount());    // "разогрев" генератора случайных чисел

	// настройка режима вывода в cout
	// boolalpha - выводить логические переменные в виде true/false вместо 1/0
	// fixed и setprecision(2) - использованные совместно означают, что
	// дробные значения (float, double) выводим в фиксированном формате с двумя
	// знаками в дробной части (после запятой)
	cout << boolalpha << fixed << setprecision(2);
} // init

// ожидание нажатия на любую клавишу  
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

