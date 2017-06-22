#include "stdafx.h"
#include "Utils.h"
#include "Application.h"
#include "Money.h"


Application::Application()
{
	// подготовка приложения к работе
	init();

	money1 = new Money();
	money2 = new Money();
} // Application::Application


Application::~Application()
{
	delete money1, money2;

	waitForKey("Нажмите любую клавишу для завершения...");
} // Application::~Application

void Application::run()
{
	// тестирование разработанных операций и методов

	testInOut();         // ввод и вывод

	testArithmetics();  // арифметические операции

	testComparisions(); // операции сравнения и отношения
	
} // Application::run


// тестируем ввод/вывод
void Application::testInOut()
{
	cout << "\n\nТест операций ввода/вывода: старт\n";
	cout << "\nВведите сумму 1 (рубли копейки): ";
	cin >> *money1;
	cout << "\nВы ввели: " << *money1 << "\n";

	cout << "\nВведите сумму 1 (рубли копейки) и сумму 2 (рубли копейки): ";
	cin >> *money1 >> *money2;
	cout << "\nВы ввели: " << *money1 << " и " << *money2 << "\n";

	// Преобразование в строку и вывод:
	cout << "\nПреобразование сумм в строковый формат: "
		<< money1->toString() << "; " << money2->toString() << "\n";

	cout << "\nТест операций ввода/вывода: финиш\n";
} // Application::testInOut

// тестируем перегруженные арифметические операции
void Application::testArithmetics()
{
	cout << "\n\nТест арифметических операций: старт\n\n";

	cout << *money1 << " + " << *money2 <<" = " << *money1 + *money2 << "\n";
	cout << *money1 << " - " << *money2 <<" = " << *money1 - *money2 << "\n";

	double Rate = 1. / 58.;  // курс рубля к доллару
	// операция вида Rate * money - не может быть перегружена методом класса
	cout << setprecision(5) << Rate << " * " << setprecision(2) << *money1 << " = " << (*money1) * Rate << "\n";
	cout << "\nТест арифметических операций: финиш\n";
} // Application::testArithmetics

// тестируем перегруженные операции сравнения и отношения
void Application::testComparisions()
{
	cout << "\n\nТест операций сравнения и отношения: старт\n\n";

	bool result = *money1 == *money2;
	cout << *money1 << " == " << *money2 << " результат операции " << result << "\n";

	result = *money1 != *money2;
	cout << *money1 << " != " << *money2 << " результат операции " << result << "\n";

	result = *money1 < *money2;
	cout << *money1 << " <  " << *money2 << " результат операции " << result << "\n";

	result = *money1 <= *money2;
	cout << *money1 << " <= " << *money2 << " результат операции " << result << "\n";

	result = *money1 >= *money2;
	cout << *money1 << " >= " << *money2 << " результат операции " << result << "\n";

	result = *money1 > *money2;
	cout << *money1 << " >  " << *money2 << " результат операции " << result << "\n";

	cout << "\nТест операций сравнения и отношения: финиш\n";
} // Application::testComparisions