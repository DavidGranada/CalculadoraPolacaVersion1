#pragma once

#include"Lista.h"
class operation
{
public:
	operation();
	operation(char, char, float, float);
	void print();
	void printP();
	float valor();
	~operation();
private:
	float a, b;
	char signo, op;

};

operation::operation()
{
}

operation::operation(char s, char p, float a, float b)
{
	this->a = a;
	this->b = b;
	this->op = p;
	this->signo = s;
}
float operation::valor()
{
	float r;
	r = (op == '+' ? a + b : op == '-' ? a - b : op == '*' ? a*b : op == '/' ? a / b : 0);
	return (signo == '-' ? r*-1 : r);
}
void operation::print()
{
	cout << signo << " ( " << a << " " << op << " " << b << " ) =  " << valor() << endl;
}
void operation::printP()
{
	cout << signo << " ( " << a << " )" << " ( " << b << " ) " << " = " << valor() << endl;
}
operation::~operation()
{
}
