Triad.h 

  #pragma once

class Triad
{
protected:
	int a, b, c;
public:
	Triad increaseA();
	Triad increaseB();
	Triad increaseC();
	void setA(int A) { a = A; }
	//void setB, setC
	int getA() { 
		return a;
	}
	int getB() { return b; 
	}
	// getB, getC

	std::string toString();
};


Triad.cpp

  #include <iostream>
#include "Triad.h"

void Triad::increaseA()
{
	a++;
}
void Triad::increaseB()
{
	b++;
}
void Triad::increaseC()
{
	c++;
}

Time.h

  #include "Triad.h"
#pragma once

class Time : public Triad
{
private:
	void normalize();
public:
	void increaseM(int);
	void increaseS(int);

	//	Override
	Time increaseA();
	Time increaseB();
	Time increaseC();

	std::string toString();
};
#pragma once


Time.cpp

  #include <iostream>
#include <string>
#include "Time.h"

Time Time::increaseM(int n)
{
	//for i=0 to n-1
	m += n;
	normalize();
}
void Time::increaseS(int n)
{
	s += n;
	normalize();
}
void Time::normalize()
{
	m += s / 60;
	s = s % 60;
	h += m / 60;
	m = m % 60;
}

//	Override
Time Time::increaseA()
{
	Triad tmp = Triad::increaseA();
	Time res(tmp.getA(), tmp.getB(), tmp.getC());
	res.normalize();
	return res;
}

void Time::increaseB()
{
	b += 10;
}

void Time::increaseC()
{
	c += 10;
}

std::string Time::toString()
{
	return std::to_string(h) + ':'
		+ std::to_string(m) + ':'
		+ std::to_string(s);
}

main.cpp

  #include <iostream>
#include "Triad.h"
#include "Time.h"

int main()
{
    Triad tr = Triad();
    Time t = Time();

    t.h = 10;
    t.m = 15;
    t.s = 26;

    std::cout << "Triad::A = " << tr.a << std::endl;
    std::cout << "Time::A = " << t.a << std::endl;

    tr.increaseA();
    t.increaseA();

    std::cout << "Triad::A = " << tr.a << std::endl;
    std::cout << "Time::A = " << t.a << std::endl;

    std::cout << t.toString() << std::endl;

    t.increaseM(35);
    t.increaseS(20);

    std::cout << t.toString() << std::endl;

    return 0;
}
