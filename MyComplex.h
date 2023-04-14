#pragma once
#include <iostream>

double pi = 3.1415926535897932384626433832795;

struct MyComplex {
    MyComplex();
    MyComplex(double x, double y);

    void set_Real(double R);
    void set_Image(double I);

    double get_abs();
    double get_angle();
    double get_Real();
    double get_Imag();

    MyComplex conjugate();

    MyComplex operator- ();

    MyComplex operator+ (MyComplex Num);
    MyComplex operator+ (double Num);

    MyComplex operator- (MyComplex Num);
    MyComplex operator- (double Num);

    MyComplex operator* (MyComplex Num);
    MyComplex operator* (double Num);

    MyComplex operator/ (MyComplex Num);
    MyComplex operator/ (double Num);

    MyComplex operator^ (int power);
    MyComplex pow(int power);


private:
    double Real_part;
    double Imag_part;
};

std::istream& operator>> (std::istream& is, MyComplex& Num);
std::ostream& operator<< (std::ostream& os, MyComplex& Num);