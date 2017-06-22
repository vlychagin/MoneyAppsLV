#pragma once
#include "Money.h"

class Application
{
public:
	static const int N_MONEY = 5;     // ������ ������� �������� ����
	static const double EURO_RATE;    // ���� ����
	static const double DOLLAR_RATE;  // ���� �������

	private:
	// ��������� �� ������ ���� �����
	Money *money;
	

public:
	Application();
	~Application();

	void run();

	Money *toEuros();
	Money *toDollars();

};

