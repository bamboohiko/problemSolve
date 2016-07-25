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
struct edge{
	int x,y,dis;
};
edge a[10100];
int f[110];
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
bool cmp(edge a,edge b)
{
	return a.dis < b.dis;
}
int main()
{
	int n;
	while (scanf("%d",&n) != EOF && n)
	{
		int m = 0,sum = 1,ans = 0;
		for (int i = 1;i <= n; i++) f[i] = i;
		for (int i = 1;i <= n*(n-1)/2; i++)
		{
			int d;
			scanf("%d%d%d%d",&a[m].x,&a[m].y,&a[m].dis,&d);
			if (d)
			{
				int x = find(a[m].x),y = find(a[m].y);
				if (x != y)
				{
					f[x] = y;
					sum++;
				}
			}
			m += 1-d;
		}
		sort(a,a+m,cmp);
		for (int i = 0;i < m && sum <= n; i++)
		{
			int x = find(a[i].x),y = find(a[i].y);
			if (x != y)
			{
				f[x] = y;
				sum++;
				ans += a[i].dis;
			}
		}
		printf("%d\n",ans);
	} 
	return 0;
}

