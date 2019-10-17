#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double da = 0.0005;
double fun(double a, double b) {
	return (exp(a) + sqrt(b)) / log(a + b * b);
}


double max(double a, double b)
{
	double c = 0, d = 0;
	double max = fun(a, b);
	for (int i = -50; i <= 50; i++)
	{
		c = a + 0.00001 * i;
		for (int j = -50; j <= 50; j++)
		{
			d = b + 0.00001 * j;
			if (max < fun(c, d))
				max = fun(c, d);
		}
	}
	cout<<"max="<<max<<endl;
	return max;
}

double min(double a, double b)
{
	double c = 0, d = 0;
	double min = fun(a, b);
	for (int i = -50; i <= 50; i++)
	{
		c = a + 0.00001 * i;
		for (int j = -50; j <= 50; j++)
		{
			d = b + 0.00001 * j;
			if (min > fun(c, d))
				min = fun(c, d);
		}
	}
	cout<<"min="<<min<<endl;
	return min;
}

void main()
{
	double A, a = 2.156, b = 0.927, d = 0.0005;// x<=0.5 => x<=0.05 => x<=0.005 => x<=0.0005 => погрешность меньше или равно 0.0005
	A = fun(a, b);
	min(a, b);
	max(a, b);
	cout<<(max(a, b) - min(a, b)) / 2<<endl;
	d = abs((fun(a + da, b + da) - fun(a - da, b - da)));
	cout << A << endl<< d<<endl;
}