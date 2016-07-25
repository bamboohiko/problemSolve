#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct point{
	double x,y;
	point(double x=0,double y=0):x(x),y(y) {}
};
point a[110];
const int r = 6730;
const double pi = 3.1415926;
double dis(point i,point j)
{
	double t = r*acos(sin(i.y)*sin(j.y)*cos(i.x-j.x)+cos(i.y)*cos(i.y));
	cout << t << endl;
	return r*acos(sin(i.y)*sin(j.y)*cos(i.x-j.x)+cos(i.y)*cos(i.y));
}
int main()
{int n;
	while (cin >> n)
		{double ans = 10*r;
		for (int i = 1;i <= n; i++)
			{cin >> a[i].x >> a[i].y;
			a[i].x = a[i].x/180*pi;
			a[i].y = a[i].y/180*pi;  
			}
		for (int i = 1;i < n; i++)
			for (int j = i+1;j <= n; j++)
				ans = min(ans,dis(a[i],a[j]));
		printf("%.2lf\n",ans);
		}
	return 0;
}
