#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct point{
	double x,y;
} p1,p2,p3;
double a,b,c,k,h;
double f(double x)
{
	return (a/3)*x*x*x + ((b - k)/2)*x*x + (c - h)*x;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
		if (p2.x > p3.x) swap(p2,p3);
		a = (p2.y - p1.y)/(p2.x - p1.x)/(p2.x - p1.x);
		b = a*(-2)*p1.x;
		c = a*p1.x*p1.x +p1.y;
		//cout << a << " " << b << " " << c << endl;
		k = (p3.y - p2.y)/(p3.x - p2.x);
		h = p2.y - k*p2.x;
		//cout << k << " " << h << endl;
		printf("%.2lf\n",f(p3.x) - f(p2.x));
	}
	return 0;
}
