#include "MyComplex.h"

MyComplex::MyComplex()
    :Real_part(0), Imag_part(0)
{}
MyComplex::MyComplex(double x = 0, double y = 0) 
    :Real_part (x), Imag_part (y)
{}
 
void MyComplex::set_Real(double R) {
    Real_part = R;
}

void MyComplex::set_Image(double I) {
    Imag_part = I;
}

double MyComplex::get_abs() {
    return(sqrt(Real_part * Real_part + Imag_part * Imag_part));
}

double MyComplex::get_angle() {

    double angle = atan(Imag_part / Real_part);
    if (Real_part < 0) {

        if (Imag_part < 0) {
            angle -= pi;
        }
        else {
            angle += pi;
        }
    }
    return(angle);
}

double MyComplex::get_Real() {
    return(this->Real_part);
}

double MyComplex::get_Imag() {
    return(this->Imag_part);
}

MyComplex MyComplex::conjugate() {
    return(MyComplex(Real_part, -Imag_part));
}

MyComplex MyComplex:: operator- () {
    return(MyComplex(-Real_part, -Imag_part));
}

MyComplex MyComplex:: operator+ (MyComplex Num) {
    return(MyComplex(Real_part + Num.get_Real(), Imag_part + Num.get_Imag()));
}
MyComplex MyComplex:: operator+ (double Num) {
    return(MyComplex(Real_part + Num, Imag_part));
}

MyComplex MyComplex:: operator- (MyComplex Num) {
    return(MyComplex(Real_part - Num.get_Real(), Imag_part - Num.get_Imag()));
}
MyComplex MyComplex:: operator- (double Num) {
    return(MyComplex(Real_part - Num, Imag_part));
}

MyComplex MyComplex:: operator* (MyComplex Num) {
    double a1 = Real_part * Num.get_Real();
    double a2 = Real_part * Num.get_Imag();
    double a3 = Imag_part * Num.get_Real();
    double a4 = -(Imag_part * Num.get_Imag());

    return(MyComplex(a1 + a4, a2 + a3));
}
MyComplex MyComplex:: operator* (double Num) {
    return(MyComplex(Real_part * Num, Imag_part * Num));
}

MyComplex MyComplex:: operator/ (MyComplex Num) {
    double a1 = Real_part * Num.get_Real();
    double a2 = Imag_part * Num.get_Imag();
    double a3 = Imag_part * Num.get_Real();
    double a4 = Real_part * Num.get_Imag();
    double denominator = Num.get_Real() * Num.get_Real() + Num.get_Imag() * Num.get_Imag();

    return(MyComplex((a1 + a2) / denominator, (a3 - a4) / denominator));
}
MyComplex MyComplex:: operator/ (double Num) {
    return(MyComplex(Real_part / Num, Imag_part / Num));
}

MyComplex MyComplex:: operator^ (int power) {
    if (power == 0) {
        return(MyComplex(1, 0));
    }
    else if (power > 0) {

        double r = this->get_abs();
        double r_pow = r;
        for (int i = 2; i <= power; i++)
            r_pow *= r;

        double angle = this->get_angle();

        double a1 = cos(power * angle);
        double a2 = sin(power * angle);

        return(MyComplex(r_pow * a1, r_pow * a2));
    }
    else {

        power = -power;

        double r = this->get_abs();
        double r_pow = r;
        for (int i = 2; i <= power; i++)
            r_pow *= r;

        double angle = this->get_angle();

        double a1 = cos(power * angle);
        double a2 = sin(power * angle);

        return(MyComplex(1, 0) / MyComplex(r_pow * a1, r_pow * a2));
    }
}
MyComplex MyComplex:: pow(int power) {
    if (power == 0) {
        return(MyComplex(1, 0));
    }
    else if (power > 0) {

        double r = this->get_abs();
        double r_pow = r;
        for (int i = 2; i <= power; i++)
            r_pow *= r;

        double angle = this->get_angle();

        double a1 = cos(power * angle);
        double a2 = sin(power * angle);

        return(MyComplex(r_pow * a1, r_pow * a2));
    }
    else {

        power = -power;

        double r = this->get_abs();
        double r_pow = r;
        for (int i = 2; i <= power; i++)
            r_pow *= r;

        double angle = this->get_angle();

        double a1 = cos(power * angle);
        double a2 = sin(power * angle);

        return(MyComplex(1, 0) / MyComplex(r_pow * a1, r_pow * a2));
    }
}

std::istream& operator>> (std::istream& is, MyComplex& Num) {
    double R, I;
    is >> R >> I;
    Num.set_Real(R);
    Num.set_Image(I);
    return is;
}

std::ostream& operator<< (std::ostream& os, MyComplex& Num) {
    if (Num.get_Imag() >= 0) {
        os << Num.get_Real() << " + i" << Num.get_Imag() << '\n';
    }
    else {
        os << Num.get_Real() << " - i" << -Num.get_Imag() << '\n';
    }
    return os;
}