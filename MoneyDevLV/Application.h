#pragma once
#include "Money.h"

class Application
{
	// указатели на объекты для  тестирования
	Money *money1, *money2;

	// методы для организации тестирования класса Money
	void testInOut();         // тестируем ввод/вывод
	void testArithmetics();   // тестируем арифметические операции
	void testComparisions();  // тестируем операции сравнения и отношения 

public:
	Application();
	~Application();

	void run();
};

