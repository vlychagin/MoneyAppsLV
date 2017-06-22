// ► Разработать класс Money для представления сумм (в рублях и копейках) 
//   с набором конструкторов, геттеров и сеттеров, методом toString()
// ► При помощи методов класса перегрузите операции:
//   + для сложения двух сумм 
//   - для вычитания двух сумм
//   * для умножения суммы на вещественное число – перевод в другую валюту
// ► При помощи дружественных функций перегрузите операции 
//   ввода и вывода, 
//   сравнения(== , != ) и отношения(<, <= , >= , >).
//   Для реализации сравнений и отношений переведите сумму в копейки и сравнивайте 
//   полученные числа

#pragma once
#include "stdafx.h"

class Money
{
	// опеределение синонима типа
	// typedef новыйТип старыйТип;
	// пример:
	// typedef unsigned char byte;
	long _rubles;  // рубли
	int  _copecs;  // копейки

	char strBuf[80];  // буфер для строкового представления суммы

public:
	// ансамбль конструкторов, начальное значение полей - нули
	// Инициализация в списке выполняется в порядке объявления полей в классе,
	// но не в порядке перечисления полей в списке инициализации 
	Money() : _rubles(), _copecs() {}
	Money(long rubles, int copecs): _rubles(), _copecs()
	{
		setRubles(rubles);
		setCopecs(copecs);
	} // Money
	Money(const Money &money): _rubles(money._rubles), _copecs(money._copecs) {}
	
	~Money() {}  // деструктор, не используется в данном проекте

	// геттеры и сеттеры

	long rubles() const { return _rubles; }
	void setRubles(long rubles) 
	{
		// рубли могут быть отрицательными - по результатам
		// выполнения операций, знак суммы будем хранить именно
		// в поле рублей
		_rubles = rubles;
	} // setRubles


	int copecs() const { return _copecs; }
	void setCopecs(int copecs)
	{
		// копейки будут только положительными и принадлежать
		// интервалу от 0 до 99 (включительно)
		if (copecs >= 0 && copecs <= 99)
			_copecs = copecs;
	} // setCopecs 

	// в этот буфер выводим сумму, преобразованную в строковый формат
	char *toString();

	// операторы, перегруженные для этого класса
	Money operator+(Money &money) const;
	Money operator-(Money &money) const;
	Money operator*(double Rate) const;
	Money &operator += (Money &money);

	// операторы ввода и вывода
	friend istream& operator >> (istream &stream, Money &money);
	friend ostream& operator << (ostream &stream, const Money &money);

	// вспомогательный метод - типичная реализация сравнения
	int compareTo(const Money &money) const;

	// операторы сравнения и отношения
	friend bool operator==(const Money& money1, const Money& money2);
	friend bool operator!=(const Money& money1, const Money& money2);
	friend bool operator>=(const Money& money1, const Money& money2);
	friend bool operator >(const Money& money1, const Money& money2);
	friend bool operator<=(const Money& money1, const Money& money2);
	friend bool operator <(const Money& money1, const Money& money2);

	// для удобства кодирования вычислений реализуем операцию
	// Rate * money при помощи дружественной функции
	friend Money operator*(double Rate, const Money& money);
};

