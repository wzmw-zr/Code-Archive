/*************************************************************************
	> File Name: 3.complex.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月18日 星期二 11时22分29秒
 ************************************************************************/

#include <iostream>
using namespace std;
class Complex
{
private:
  	double real;
  	double image;
public:
  	Complex(const Complex& complex) :real{ complex.real }, image{ complex.image } {

  	}
  	Complex(double Real=0, double Image=0) :real{ Real }, image{ Image } {

  	}
  	Complex operator+(Complex x) {
        Complex ret(this->real + x.real, this->image + x.image);
        return ret;
    }
    Complex operator-(Complex x) {
        Complex ret(this->real - x.real, this->image - x.image);
        return ret;
    }
    Complex operator*(Complex x) {
        Complex ret(this->real * x.real - this->image * x.image, this->real * x.image + this->image * x.real);
        return ret;
    }
    Complex operator/(Complex x) {
        double Real = this->real * x.real + this->image * x.image;
        double Image = this->image * x.real - this->real * x.image;
        double Div = x.real * x.real - x.image * x.image;
        Complex ret(Real / Div, Image / Div);
        return ret;
    }
    friend istream &operator>>(istream &in, Complex &x);
    friend ostream &operator<<(ostream &out, const Complex &x);
};

istream &operator>>(istream &in, Complex &x) {
    in >> x.real >> x.image;
    return in;
}

ostream &operator<<(ostream &out, const Complex &x) {
    out << "(" << x.real;
    if (x.image > 0) out << "+";
    out << x.image << ")";
    return out;
}


int main() {
  	Complex z1, z2;
  	cin >> z1;
  	cin >> z2;
  	cout << z1 << " " << z2 << endl;
  	cout << z1 + z2 << endl;
  	cout << z1 - z2 << endl;
  	cout << z1*z2 << endl;
  	cout << z1 / z2 << endl;
  	return 0;
}
