#include "stdafx.h"
#include "Money.h"

// �������������� ����� � ��������� ������
// ���������� ��������� �� ����������� ������ 
// char - ��������� ���� ������
char * Money::toString()
{
	sprintf(strBuf, "%d.%02d", _rubles, _copecs);
	return strBuf;
} // Money::toString

// �������� ���� �������� ����
Money Money::operator+(Money &money) const
{
	long value1 = _rubles * 100 + _copecs;
	long value2 = money._rubles * 100 + money._copecs;
	
	// ���������� �������� � ������� ����������
	// ���������� ������� ������ - ��� ����������
	// ������� ������������ ����� �� ������
	// �������� �������� �.�. ���������� �������� � ��������������
	// ���������� �� �������� ����������
	long result = value1 + value2;
	return Money(result/100, abs(result % 100));
} // Money::operator+

// �������� ���� �������� ����
Money Money::operator-(Money &money) const
{
	long value1 = _rubles * 100 + _copecs;
	long value2 = money._rubles * 100 + money._copecs;

	// ���������� �������� � ������� ����������
	// ����� ����� �������� ���� �����
	// ������� ������ ������������
	long result = value1 - value2;
	return Money(result / 100, abs(result % 100));
} // Money::operator-

// ������������ ����� �� �������������
Money Money::operator*(double Rate) const
{
	long value = _rubles * 100 + _copecs;
	
	// value = static_cast<long>(Rate * value);
	value = (long)(Rate * value);

	return Money(value / 100, abs(value % 100));
} // Money::operator* 

// ���������� ����� - ��� ������� ������ ������
// � ��������� �� ����� � ����������� �������� ����
Money & Money::operator+=(Money & money)
{
	// !!! ������� ������ �������� �� ������ �������� !!!
	long value = 100 * (_rubles + money._rubles) + _copecs + money._copecs;
	_rubles = value / 100;
	_copecs = value % 100;
	
	return *this;  // ������� ������ �� ������� ������
} // operator+=

// ���������� ��� ������� � ���������� �������� ����
// ����������
// -1  obj <  money
//  0  obj == money
//  1  obj >  money
int Money::compareTo(const Money &money) const
{
	long value1 = 100 * _rubles + _copecs;
	long value2 = 100 * money._rubles + money._copecs;

	long temp = value1 - value2;
	return temp < 0?-1:temp == 0?0:1;
} // Money::compareTo

// ��������� ����� � ������

// ����������� ���� ��� Money
istream& operator >> (istream &stream, Money &money)
{
	// ��������������� ���������� ��� �����
	long rubles;
	int copecs;

	// ����
	stream >> rubles;
	stream >> copecs;

	// ���������� �������� � ���� ������
	money.setRubles(rubles);
	money.setCopecs(copecs);

	return stream;
} // operator >>

// ����������� ����� ��� Money
ostream& operator << (ostream &stream, const Money &money)
{
	stream << money._rubles << "." 
	       << setfill('0') << setw(2) << setprecision(2) << money._copecs << setfill(' ');
	return stream;
} // operator <<

// ��������� ��������� � ��������� �������� ����

// ��� ���������� ���������� ���������� ��������������� ����� compareTo()
// ������ Money, ����������� ����������� ��������� ��� ��������� ��������
// -1 ���� money1 <  money2
//  0 ���� money1 == money2
//  1 ���� money1 >  money2
bool operator==(const Money& money1, const Money& money2)
{
	return money1.compareTo(money2) == 0;
} // operator ==

bool operator!=(const Money& money1, const Money& money2)
{
	return money1.compareTo(money2) != 0;
} // operator!=

bool operator>=(const Money& money1, const Money& money2)
{
	int result = money1.compareTo(money2);
	return result > 0 || result == 0;
} // operator>=

bool operator >(const Money& money1, const Money& money2)
{
	return money1.compareTo(money2) > 0;
} // operator>

bool operator<=(const Money& money1, const Money& money2)
{
	int result = money1.compareTo(money2);
	return result < 0 || result == 0;
} // operator<=

bool operator <(const Money& money1, const Money& money2)
{
	return money1.compareTo(money2) < 0;
} // operator<


// ���������� �������� rate * money
Money operator*(double rate, const Money & money)
{
	long value = (long)(rate * (100 * money._rubles + money._copecs));
	return Money(value / 100, abs(value % 100));
} // operator
