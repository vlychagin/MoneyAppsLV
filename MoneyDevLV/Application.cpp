#include "stdafx.h"
#include "Utils.h"
#include "Application.h"
#include "Money.h"


Application::Application()
{
	// ���������� ���������� � ������
	init();

	money1 = new Money();
	money2 = new Money();
} // Application::Application


Application::~Application()
{
	delete money1, money2;

	waitForKey("������� ����� ������� ��� ����������...");
} // Application::~Application

void Application::run()
{
	// ������������ ������������� �������� � �������

	testInOut();         // ���� � �����

	testArithmetics();  // �������������� ��������

	testComparisions(); // �������� ��������� � ���������
	
} // Application::run


// ��������� ����/�����
void Application::testInOut()
{
	cout << "\n\n���� �������� �����/������: �����\n";
	cout << "\n������� ����� 1 (����� �������): ";
	cin >> *money1;
	cout << "\n�� �����: " << *money1 << "\n";

	cout << "\n������� ����� 1 (����� �������) � ����� 2 (����� �������): ";
	cin >> *money1 >> *money2;
	cout << "\n�� �����: " << *money1 << " � " << *money2 << "\n";

	// �������������� � ������ � �����:
	cout << "\n�������������� ���� � ��������� ������: "
		<< money1->toString() << "; " << money2->toString() << "\n";

	cout << "\n���� �������� �����/������: �����\n";
} // Application::testInOut

// ��������� ������������� �������������� ��������
void Application::testArithmetics()
{
	cout << "\n\n���� �������������� ��������: �����\n\n";

	cout << *money1 << " + " << *money2 <<" = " << *money1 + *money2 << "\n";
	cout << *money1 << " - " << *money2 <<" = " << *money1 - *money2 << "\n";

	double Rate = 1. / 58.;  // ���� ����� � �������
	// �������� ���� Rate * money - �� ����� ���� ����������� ������� ������
	cout << setprecision(5) << Rate << " * " << setprecision(2) << *money1 << " = " << (*money1) * Rate << "\n";
	cout << "\n���� �������������� ��������: �����\n";
} // Application::testArithmetics

// ��������� ������������� �������� ��������� � ���������
void Application::testComparisions()
{
	cout << "\n\n���� �������� ��������� � ���������: �����\n\n";

	bool result = *money1 == *money2;
	cout << *money1 << " == " << *money2 << " ��������� �������� " << result << "\n";

	result = *money1 != *money2;
	cout << *money1 << " != " << *money2 << " ��������� �������� " << result << "\n";

	result = *money1 < *money2;
	cout << *money1 << " <  " << *money2 << " ��������� �������� " << result << "\n";

	result = *money1 <= *money2;
	cout << *money1 << " <= " << *money2 << " ��������� �������� " << result << "\n";

	result = *money1 >= *money2;
	cout << *money1 << " >= " << *money2 << " ��������� �������� " << result << "\n";

	result = *money1 > *money2;
	cout << *money1 << " >  " << *money2 << " ��������� �������� " << result << "\n";

	cout << "\n���� �������� ��������� � ���������: �����\n";
} // Application::testComparisions