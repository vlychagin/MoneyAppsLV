#pragma once
#include "Money.h"

class Application
{
	// ��������� �� ������� ���  ������������
	Money *money1, *money2;

	// ������ ��� ����������� ������������ ������ Money
	void testInOut();         // ��������� ����/�����
	void testArithmetics();   // ��������� �������������� ��������
	void testComparisions();  // ��������� �������� ��������� � ��������� 

public:
	Application();
	~Application();

	void run();
};

