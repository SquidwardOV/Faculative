pair.h

// pair.h
#pragma once

class Pair {
public:
    virtual Pair* add(const Pair& other) const = 0;
    virtual Pair* subtract(const Pair& other) const = 0;
    virtual Pair* multiply(const Pair& other) const = 0;
    virtual Pair* divide(const Pair& other) const = 0;
    virtual void print() const = 0;
    double GetA()const {
        return a;
    }
    double GetB()const {
        return b;
    }
    virtual ~Pair() = default;

protected:
    double a, b;
};

money.h

// money.h
#pragma once
#include "pair.h"

class Money : public Pair {
public:
    Money();
    Money(int rubles, int kopecks);
    Pair* add(const Pair& other) const override;
    Pair* subtract(const Pair& other) const override;
    Pair* multiply(const Pair& other) const override;
    Pair* divide(const Pair& other) const override;
    virtual ~Money() = default;
    //void normalize();
    virtual void print() const override;
    int GetRubles() {
        return a;
    }
    int GetKopecks() {
        return b;
    }
};

money.cpp

#include "money.h"
#include <stdexcept>
#include <iostream>

Money::Money()
{
    a = 0;
    b = 0;
}

Money::Money(int rubles, int kopecks)
{
    if (rubles < 0) {
        throw("Число отрицательно");
    }
    else {
        if (kopecks < 0) {
            a = rubles - 1;
            b = kopecks + 100;
        }
        else {
            a = rubles;
            b = kopecks;
        }
    }
  
}

Pair* Money::add(const Pair& other) const {
        Money* result = new Money();
        result->a = this->a + other.GetA();
        result->b = this->b + other.GetB();

        // Проверка и нормализация копеек
        if (result->b >= 100) {
            result->a += result->b / 100;
            result->b = (int) b%100;
        }
      
        return result;
}


Pair* Money::subtract(const Pair& other) const {
    
        Money* result = new Money();
        result->a = this->a - other.GetA();
        result->b = this->b - other.GetB();

        // Проверка и нормализация копеек
        if (result->b < 0) {
            result->a -= 1;
            result->b += 100;
        }
        if (result->a < 0) {
            throw std::logic_error ("Рубли отрицательное число");
        }
        return result;
 
}

Pair* Money::multiply(const Pair& other) const
{
    return nullptr;
}

Pair* Money::divide(const Pair& other) const
{
    return nullptr;
}

/*void Money::normalize() {
    // Нормализация центов
    if (b >= 100) {
        a += b / 100;
        b = (int) b%100;
    }
    else if (a < 0) {
        a -= 1;
        b += 100;
    }
}*/

void Money::print() const
{
    std::cout << "Рубли: " << a << "Копейки: " << b << std::endl;
}



complex.h

// complex.h
#pragma once
#include "pair.h"
#include <iostream>

class Complex : public Pair {
public:
    Complex(double real, double imaginary);
    Complex();
    Pair* add(const Pair& other) const override;
    Pair* subtract(const Pair& other) const override;
    Pair* multiply(const Pair& other) const override;
    Pair* divide(const Pair& other) const override;
    void print() const override;
    double GetReal() {
        return a;
    }
    double GetImaginary() {
        return b;
    }
    virtual ~Complex();

};

complex.cpp

#include "complex.h"
#include <stdexcept>

Complex::Complex(double real, double imaginary)
{
    a = real;
    b = imaginary;

}

Complex::Complex()
{
    a = 0;
    b = 0;
}

Pair* Complex::add(const Pair& other) const
{
   
        Complex* result = new Complex();
        result->a = this->a + other.GetA();
        result->b = this->b + other.GetB();
        return result;
    
    
}

Pair* Complex::subtract(const Pair& other) const
{
        Complex* result = new Complex();
        result->a = this->a - other.GetA();
        result->b = this->b - other.GetB();
        return result;
    
}

Pair* Complex::multiply(const Pair& other) const {

        Complex* result = new Complex();
        result->a = this->a * other.GetA() - this->b * other.GetB();
        result->b = this->a * other.GetB() + this->b * other.GetA();
        return result;
    
}

Pair* Complex::divide(const Pair& other) const {

        Complex* result = new Complex();
        double denominator = other.GetA() * other.GetA() + other.GetB() * other.GetB();
        result->a = (this->a * other.GetA() + this->b * other.GetB()) / denominator;
        result->b = (this->b * other.GetA() - this->a * other.GetB()) / denominator;
        return result;
   
}

void Complex::print() const
{
    std::cout << "Вещественная часть: " << a << ", Мнимая часть: " << b << std::endl;
}

Complex::~Complex()
{
}


main.cpp

#include <iostream>
#include "pair.h"
#include "money.h"
#include "complex.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(1251);
    Pair* pair1 = new Money(50, 20); 
    Pair* pair2 = new Money(20, 40);

    Pair* result1 = pair1->add(*pair2);
    Pair* result2 = pair1->subtract(*pair2);

    Money* moneyResult1 = dynamic_cast<Money*>(result1);
    if (moneyResult1) {
        moneyResult1->print();
    }

    Money* moneyResult2 = dynamic_cast<Money*>(result2);
    if (moneyResult2) {
        moneyResult2->print();
    }

    
    Pair* pair3 = new Complex(30.0, 25.0);
    Pair* pair4 = new Complex(25.0, 15.0);

    Pair* result3 = pair3->multiply(*pair4);
    Pair* result4 = pair3->divide(*pair4);

    Complex* complexResult3 = dynamic_cast<Complex*>(result3);
    if (complexResult3) {
        complexResult3->print();
    }

    Complex* complexResult4 = dynamic_cast<Complex*>(result4);
    if (complexResult4) {
        complexResult4->print();
    }
    delete pair1;
    delete pair2;
    delete result1;
    delete result2;
    delete pair3;
    delete pair4;
    delete result3;
    delete result4;

    return 0;
}

