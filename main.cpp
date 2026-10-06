#include "Vector.h"
#include <iostream>
using namespace std;

int main()
{
	double ta[] = {1, 2};
	double tb[] = {3, 4};

	Vector a(ta, 2);
	Vector b(tb, 2);

	Vector c = a + b;
	cout << "a + b = " << c[0] << " " << c[1] << endl;

	Vector d = a - b;
	cout << "a - b = " << d[0] << " " << d[1] << endl;


	Vector e = -a;
	cout << "-a = " << e[0] << " " << e[1] << endl;


	Vector f = a / 2;
	cout << "a / 2 = " << f[0] << " " << f[1] << endl;


	double s = a * b;
	cout << "a * b = " << s << endl;

	
	a *= 10;
	cout << "a *= 10 : " << a[0] << " " << a[1] << endl;


	cout << "a == a : " << (a == a) << endl;
	cout << "a != b : " << (a != b) << endl;

	return 0;
}
