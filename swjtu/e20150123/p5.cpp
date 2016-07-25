#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct point{
	double x,y;
};
point d[110];
struct edge{
	int x,y;
	double dis;
};
edge a[10100];
int f[110];
void build(int &e,int i,int j)
{
	double rec = sqrt(pow(d[i].x-d[j].x,2)+pow(d[i].y-d[j].y,2));
	if (rec >= 10 && rec <= 1000) 
	{
		a[e].x = i;
		a[e].y = j;
		a[e].dis = rec*100;
		e++;
	}
}
bool cmp(edge a,edge b)
{
	return a.dis < b.dis;
}
stack<int> s;
int find(int x)
{
	while (f[x] != x)
	{
		s.push(x);
		x = f[x];
	}
	while (!s.empty())
	{
		int k = s.top();s.pop();
		f[k] = x;
	}
	return x;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while (t--)
	{
		int e = 0;
		scanf("%d",&n);
		for (int i = 1;i <= n; i++) 
		{
			scanf("%lf%lf",&d[i].x,&d[i].y);
			f[i] = i;
		}
		for (int i = 1;i <= n; i++)
			for (int j = i+1;j <= n; j++)
				build(e,i,j);
		sort(a,a+e,cmp);
		int sum = 1; double ans = 0;
		for (int i = 0;i < e && sum <= n; i++)
		{
			int x = find(a[i].x),y = find(a[i].y);
			if (x != y)
			{
				f[x] = y;
				sum++;
				ans	+= a[i].dis;
			}
		}
		if (sum == n) printf("%.1lf\n",ans);
		else printf("oh!\n");
	}
	return 0;
}

