#include "stdafx.h"
#include "Money.h"

// преобразование суммы в строковый формат
// возвращаем указатель на статический массив 
// char - приватное поле класса
char * Money::toString()
{
	sprintf(strBuf, "%d.%02d", _rubles, _copecs);
	return strBuf;
} // Money::toString

// сложение двух денежных сумм
Money Money::operator+(Money &money) const
{
	long value1 = _rubles * 100 + _copecs;
	long value2 = money._rubles * 100 + money._copecs;
	
	// выполнение операции и возврат результата
	// абсолютное значние копеек - для выполнения
	// правила формирования суммы со знаком
	// Знаковое сложение м.б. вследствие операций с отрицательными
	// значениями из операции вычитангия
	long result = value1 + value2;
	return Money(result/100, abs(result % 100));
} // Money::operator+

// разность двух денежных сумм
Money Money::operator-(Money &money) const
{
	long value1 = _rubles * 100 + _copecs;
	long value2 = money._rubles * 100 + money._copecs;

	// выполнение операции и возварт результата
	// рубли могут отражать знак суммы
	// копейки всегда положительны
	long result = value1 - value2;
	return Money(result / 100, abs(result % 100));
} // Money::operator-

// произведение суммы на коэфффицитент
Money Money::operator*(double Rate) const
{
	long value = _rubles * 100 + _copecs;
	
	// value = static_cast<long>(Rate * value);
	value = (long)(Rate * value);

	return Money(value / 100, abs(value % 100));
} // Money::operator* 

// накопление суммы - для решения второй задачи
// с переводом по курсу и вычислением итоговых сумм
Money & Money::operator+=(Money & money)
{
	// !!! Текущий объект меняется по логике операции !!!
	long value = 100 * (_rubles + money._rubles) + _copecs + money._copecs;
	_rubles = value / 100;
	_copecs = value % 100;
	
	return *this;  // вернуть ссылку на текущий объект
} // operator+=

// Компаратор для текущей и переданной денежных сумм
// возвращает
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

// операторы ввода и вывода

// перегружаем ввод для Money
istream& operator >> (istream &stream, Money &money)
{
	// вспомогательные переменные для ввода
	long rubles;
	int copecs;

	// ввод
	stream >> rubles;
	stream >> copecs;

	// корректная передача в поля класса
	money.setRubles(rubles);
	money.setCopecs(copecs);

	return stream;
} // operator >>

// перегружаем вывод для Money
ostream& operator << (ostream &stream, const Money &money)
{
	stream << money._rubles << "." 
	       << setfill('0') << setw(2) << setprecision(2) << money._copecs << setfill(' ');
	return stream;
} // operator <<

// операторы сравнения и отношения денежных сумм

// для реализации перегрузки используем вспомогательный метод compareTo()
// класса Money, реализующий стандартное поведение при сравнении объектов
// -1 если money1 <  money2
//  0 если money1 == money2
//  1 если money1 >  money2
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


// Реализация операции rate * money
Money operator*(double rate, const Money & money)
{
	long value = (long)(rate * (100 * money._rubles + money._copecs));
	return Money(value / 100, abs(value % 100));
} // operator
