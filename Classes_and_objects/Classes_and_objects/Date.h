#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

class Date
{
public:
	Date(int year=0, int mouth=1, int day=1);
	void Print();
	int GetMouthDay(int year, int mouth);

	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator>=(const Date& d);
	bool operator<=(const Date& d);
	bool operator==(const Date& d);
	Date& operator=(const Date& d);
	bool operator!=(const Date& d);

	//d1+=xxx
	Date& operator+=(int day);
	//d1+xxx
	Date operator+(int day);
	//d1++
	Date& operator++();
	//++d1 后置++为了取分前置++，增加一个参数占位
	Date operator++(int);
	//d1-=xxx
	Date& operator-=(int day);
	//d1-xxx
	Date operator-(int day);
private:
	int _year;
	int _mouth;
	int _day;
};