#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
double a,b,c,d;
int f(int x)
{int t = x/1000;
	return abs(a*t*t*t+b*t*t+c*t+d);
}
int main()
{double l,r;
	while (scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&l,&r) != EOF)
		{int AL = l*1000,R = r*1000;
		double ans = f(L);
		for (int i = L+1;i <= R; i++)
			ans = max(ans,f(i));
		printf("%.2lf\n",ans);
		}
	return 0;
}
