#include "stdafx.h"
#include "Utils.h"
#include "Application.h"
#include "Money.h"

// Х —оздание динамического массива сумм в рубл€х
// Х ѕеревод этого массива в доллары, евро
// Х ќпределение итоговой суммы в рубл€х, долларах и евро

// курс евро и доллара http://zenrus.ru/
// инициализаци€ констант вне объ€влени€ класса
const double Application::EURO_RATE = 1. / 64.47;   
const double Application::DOLLAR_RATE = 1. / 57.49;

// подготовка приложени€ - создание и инициализаци€ массива
Application::Application()
{
	// подготовка приложени€ к работе
	init();

	// создание и инициализаци€ динамического массива сумм
	money = new Money[N_MONEY] {
		Money(100, 0),
		Money(500, 0),
		Money(1000, 0),
		Money(5000, 0),
		Money(10000, 0)
	};
} // Application::Application


// завершение приложени€ - освободить пам€ть
Application::~Application()
{
	delete[] money;

	waitForKey("Ќажмите любую клавишу дл€ завершени€...");
} // Application::~Application

// основной метод приложени€ - выполн€ет всю полезную работу
void Application::run()
{
	Money *euros = toEuros();
	Money *dollars = toDollars();

	cout << "\n"
		<< "+----------------+---------------+------------------+\n"
		<< "| —умма в рубл€х |  —умма в евро | —умма в долларах |\n"
		<< "+----------------+---------------+------------------+\n";
	for (int i = 0; i < N_MONEY; i++) {
		cout << "| " << setw(10) << money[i] << "  |" 
		     << setw(10) << euros[i] << "  |   " 
		     << setw(10) << dollars[i] << "  |\n";
	} // for i
	cout << "+----------------+---------------+------------------+\n";

	// расчет итоговых сумм - дл€ решени€ задачи требуетс€ перегрузить
	// операцию +=
	Money sumRubles(0, 0);
	Money sumEuros (0, 0);
	Money sumDollars(0, 0);

	for (int i = 0; i < N_MONEY; ++i) {
		sumRubles += money[i];
		sumEuros += euros[i];
		sumDollars += dollars[i];
	} // for i

	// вывод итоговых сумм
	cout << "| " 
		<< setw(10) << sumRubles << "  |"
		<< setw(10) << sumEuros  << "  |   "
		<< setw(10) << sumDollars << "  |\n"
		<< "+----------------+---------------+------------------+\n";

	delete[] euros;
	delete[] dollars;
} // Application::run

// преобразование в евро - возвращает новый массив Money
// применение операции  Money * double
Money * Application::toEuros()
{
	Money *temp = new Money[N_MONEY];
	for (int i = 0; i < N_MONEY; i++) {
		temp[i] = money[i] * EURO_RATE;
	} // for i
	return temp;
} // Application::toEuros

// перобразование в доллары - возвращает новый массив Money
// применение операции double * Money
Money * Application::toDollars()
{
	Money *temp = new Money[N_MONEY];
	for (int i = 0; i < N_MONEY; i++) {
		temp[i] = DOLLAR_RATE * money[i];
	} // for i
	return temp;
} // Application::toDollars
