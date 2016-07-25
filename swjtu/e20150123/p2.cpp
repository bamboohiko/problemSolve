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
edge a[10010];
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
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF)
	{
		for (int i = 0;i < m; i++)
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].dis);
		for (int i = 0;i < n; i++) f[i] = i;
		sort(a,a+m,cmp);
		int sum = 1,ans = 0;
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
		if (sum < n) printf("impossible\n");
		else printf("%d\n",ans);
		printf("\n");
	}
	return 0;
}

