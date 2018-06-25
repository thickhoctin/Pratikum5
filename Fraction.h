#include <string>
using namespace std;


class Fraction
{
	
public:
	Fraction(int num = 0, int denom = 1);
	//Fraction();
	//~Fraction();
	
	bool operator<(const Fraction&);
	
	void read();
	Fraction add(const Fraction&);
	Fraction subtract(const Fraction&);
	Fraction multiply(const Fraction&);
	Fraction divide(const Fraction&);
	string toString();
	int num;
	int denom;

	friend ostream& operator<< (ostream&, const Fraction&);
	friend istream& operator>> (istream&, const Fraction&);
	friend Fraction operator+(Fraction&, Fraction&);
	friend Fraction operator-(Fraction&, Fraction&);
	friend Fraction operator*(Fraction&, Fraction&);
	friend Fraction operator/(Fraction&, Fraction&);
private:
	
	int gcd(int, int);
	void cancel();
	void format();

};


