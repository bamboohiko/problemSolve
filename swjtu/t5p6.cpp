#include<iostream>
#include<cstdio>
using namespace std;
const double NI = 1e-7;
double a,b,c,d;
double f(double x)
{
    return a*x*x*x+b*x*x+c*x-d;
}
double ft(double x)
{
    return 3*a*x*x+2*b*x+c;
}
int main()
{double x0 = 0,x = 0;
    cin >> a >> b >> c >> d;
    do
    {double t1,t2;
    x0 = x;
    t1 = f(x0);
    t2 = ft(x0);
    x = x0 - t1/t2;
    }while (f(x) > NI);
	printf("%.4lf",x);
    return 0;
}



