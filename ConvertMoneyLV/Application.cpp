#include "stdafx.h"
#include "Utils.h"
#include "Application.h"
#include "Money.h"

// � �������� ������������� ������� ���� � ������
// � ������� ����� ������� � �������, ����
// � ����������� �������� ����� � ������, �������� � ����

// ���� ���� � ������� http://zenrus.ru/
// ������������� �������� ��� ���������� ������
const double Application::EURO_RATE = 1. / 64.47;   
const double Application::DOLLAR_RATE = 1. / 57.49;

// ���������� ���������� - �������� � ������������� �������
Application::Application()
{
	// ���������� ���������� � ������
	init();

	// �������� � ������������� ������������� ������� ����
	money = new Money[N_MONEY] {
		Money(100, 0),
		Money(500, 0),
		Money(1000, 0),
		Money(5000, 0),
		Money(10000, 0)
	};
} // Application::Application


// ���������� ���������� - ���������� ������
Application::~Application()
{
	delete[] money;

	waitForKey("������� ����� ������� ��� ����������...");
} // Application::~Application

// �������� ����� ���������� - ��������� ��� �������� ������
void Application::run()
{
	Money *euros = toEuros();
	Money *dollars = toDollars();

	cout << "\n"
		<< "+----------------+---------------+------------------+\n"
		<< "| ����� � ������ |  ����� � ���� | ����� � �������� |\n"
		<< "+----------------+---------------+------------------+\n";
	for (int i = 0; i < N_MONEY; i++) {
		cout << "| " << setw(10) << money[i] << "  |" 
		     << setw(10) << euros[i] << "  |   " 
		     << setw(10) << dollars[i] << "  |\n";
	} // for i
	cout << "+----------------+---------------+------------------+\n";

	// ������ �������� ���� - ��� ������� ������ ��������� �����������
	// �������� +=
	Money sumRubles(0, 0);
	Money sumEuros (0, 0);
	Money sumDollars(0, 0);

	for (int i = 0; i < N_MONEY; ++i) {
		sumRubles += money[i];
		sumEuros += euros[i];
		sumDollars += dollars[i];
	} // for i

	// ����� �������� ����
	cout << "| " 
		<< setw(10) << sumRubles << "  |"
		<< setw(10) << sumEuros  << "  |   "
		<< setw(10) << sumDollars << "  |\n"
		<< "+----------------+---------------+------------------+\n";

	delete[] euros;
	delete[] dollars;
} // Application::run

// �������������� � ���� - ���������� ����� ������ Money
// ���������� ��������  Money * double
Money * Application::toEuros()
{
	Money *temp = new Money[N_MONEY];
	for (int i = 0; i < N_MONEY; i++) {
		temp[i] = money[i] * EURO_RATE;
	} // for i
	return temp;
} // Application::toEuros

// �������������� � ������� - ���������� ����� ������ Money
// ���������� �������� double * Money
Money * Application::toDollars()
{
	Money *temp = new Money[N_MONEY];
	for (int i = 0; i < N_MONEY; i++) {
		temp[i] = DOLLAR_RATE * money[i];
	} // for i
	return temp;
} // Application::toDollars
