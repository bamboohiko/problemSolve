#include<cstdio>
#include<cmath>
using namespace std;
double eps = 1e-9;
double a;
double f(double x)
{
	return x*x*x-a;
}
double ft(double x)
{
	return 3*x*x;
}
int main()
{
	scanf("%lf",&a);
	 double x = 1,x0 = 1;
	do
	{x0 = x;
	double t1 = f(x0),t2 = ft(x0);
	x = x0 - f(x0)/ft(x0);
	}while (abs(x - x0) > eps);
	printf("%.4lf\n",x);
	return 0;
}
