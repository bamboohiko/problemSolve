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
edge a[50010];
int f[1010];
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
		int k = s.top(); s.pop();
		f[k] = x;
	}
	return x;
}
int main()
{
	int t,n,m,k;
	scanf("%d",&t);
	while (t--)
	{
		int sum = 1,ans = 0;
		scanf("%d%d%d",&n,&m,&k);
		for (int i = 1;i <= n; i++) f[i] = i;
		for (int i = 0;i < m; i++)
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].dis);
		for (int i = 1;i <= k; i++)
		{
			int s,x,y;
			scanf("%d%d",&s,&x);
			for (int i = 2;i <= s; i++)
			{
				scanf("%d",&y);
				int nx = find(x),ny = find(y);
				if (nx != ny)
				{
					f[nx] = ny;
					sum++;
				}
			}
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
		if (sum < n) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}

