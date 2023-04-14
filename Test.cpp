#include <iostream>
#include "MyComplex.h"

void FullTest(MyComplex Num);

int count = 1;

int main()
{

    MyComplex Num0(111, 222);

    MyComplex Num1;
    MyComplex Num2;
    std::cout << "Input Real and Imaginary part of Complex number" << '\n';
    std::cin >> Num2;
    MyComplex Num3(1, 1);
    MyComplex Num4(-1, -1);
    MyComplex Num5(153.12, -22.15);

    MyComplex Num6 = Num5.conjugate();

    MyComplex Num7 = -Num5;

    MyComplex Num8 = Num5 + Num0;
    MyComplex Num9 = Num5 * Num0;
    MyComplex Num10 = Num5 / Num0;

    MyComplex Num11 = Num5 + 10;
    MyComplex Num12 = Num5 * 10;
    MyComplex Num13 = Num5 / 10;

    MyComplex Num14 = Num5 ^ 3;
    MyComplex Num15 = Num5.pow(3);
    MyComplex Num16 = Num5 ^ (-2);

    const int len = 16;
    int start = 1;
    MyComplex testArr[len] = { Num1,Num2,Num3, Num4, Num5, Num6, Num7, Num8, Num9, Num10, Num11, Num12, Num13, Num14, Num15, Num16 };

    for (int i = start - 1; i < len; i++) {
        count = i + 1;
        FullTest(testArr[i]);
    }
}

void FullTest(MyComplex Num) {

    double R = Num.get_Real();
    double I = Num.get_Imag();
    double M = Num.get_abs();
    double F = Num.get_angle();

    std::cout << "Num" << count << " = " << Num << '\n';

    std::cout << "ABS = " << M << ", Angle = " << F << '\n';
    std::cout << '\n';
}

