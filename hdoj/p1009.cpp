#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct point{
	double v,p;
};
point a[1010];
bool cmp(point a,point b)
{
	return a.p*b.v > b.p*a.v;
}
int main()
{int m,n;
	while(cin >> m >> n && m != -1 && n != -1)
		{for (int i = 0;i < n;i++)
			cin >> a[i].p >> a[i].v;
		sort(a,a+n,cmp);
		double sum = 0;
		for (int i = 0;i < n;i++)
			if (m > a[i].v) 
				{m-=a[i].v;
				sum+=a[i].p;
				}
			else 
				{sum+=a[i].p*m/a[i].v;
				break;
				}
		printf("%.3lf\n",sum);
		}
}
