#include <iostream>
#include <string>
#include <sstream>

#include "Fraction.h"

using namespace std;

Fraction::Fraction(int num , int denom ) {
	this->num = num;
	this->denom = denom;
}

int Fraction::gcd(int p, int q) {
	int temp;
	while (q != 0)
	{
		temp = p % q;
		p = q;
		q = temp;
	}
	return p;
}

void Fraction::cancel() {
	int gcdNumDenom = gcd(num, denom);
	if (gcdNumDenom < 0)
	{
		gcdNumDenom *= -1;
	};
	num /= gcdNumDenom;
	denom /= gcdNumDenom;
}

Fraction Fraction::add(const Fraction& f) {
	Fraction result;
	result.num = num * f.denom + denom * f.num;
	result.denom = denom * f.denom;
	result.cancel();
	result.format();
	return result;
}
Fraction Fraction::subtract(const Fraction& f) {
	Fraction result;
	result.num = num * f.denom - denom * f.num;
	result.denom = denom * f.denom;
	result.cancel();
	result.format();
	return result;
}
Fraction Fraction::multiply(const Fraction& f) {
	Fraction result;
	result.num = num * f.num;
	result.denom = denom * f.denom;
	result.cancel();
	result.format();
	return result;
}
Fraction Fraction::divide(const Fraction& f) {
	Fraction result;
	result.num = num* f.denom;
	result.denom = denom * f.num;
	result.cancel();
	result.format();
	return result;
}

void Fraction::format() {

	if (denom < 0)
	{
		num *= -1;
		denom *= -1;
	}
}
void Fraction::read() {
	cout << "Zaehler: ";
	cin >> num;

	cout << "Nenner: ";
	cin >> denom;
	while (denom == 0)
	{
		cout << "Nenner darf nicht Null sein!\n" << endl;
		cout << "Nenner: ";
		cin >> denom;
	}

}

string Fraction::toString() {
	stringstream outString;
	outString << num << "/" << denom;
	return outString.str();
}


ostream& operator<<(ostream& out, const Fraction& f) {
	out << f.num << "/" <<f.denom << endl;
	return out;
}

istream& operator>>(istream& in, Fraction& f) {
	in >> f.num >> f.denom;
	return in;
}

bool Fraction::operator<(const Fraction& f) {
	return (num / denom) < (f.num / f.denom);
}

Fraction operator+(Fraction& f1, Fraction& f2) {
	return f1.add(f2);
}

Fraction operator-(Fraction& f1, Fraction& f2) {
	return f1.subtract(f2);
}

Fraction operator*(Fraction& f1, Fraction& f2) {
	return f1.multiply(f2);
}

Fraction operator/(Fraction& f1, Fraction& f2) {
	return f1.divide(f2);
}




