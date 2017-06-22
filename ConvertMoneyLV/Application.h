#pragma once
#include "Money.h"

class Application
{
public:
	static const int N_MONEY = 5;     // размер массива денежных сумм
	static const double EURO_RATE;    // курс евро
	static const double DOLLAR_RATE;  // курс доллара

	private:
	// указатель на массив сумм денег
	Money *money;
	

public:
	Application();
	~Application();

	void run();

	Money *toEuros();
	Money *toDollars();

};

