#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
class Stack
{
private:
	int* _a;
	int _top;
	int _capacity;
public:
	void Init();
	void Push(int x);
};