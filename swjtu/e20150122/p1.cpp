#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int f[1000 + 10];
stack<int> s;
int find(int x)
{
	s.empty();
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
	int t,n,m;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n; ++i) f[i] = i;
		int ans = n;
		for (int i = 1;i <= m; ++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x = find(x);y = find(y);
			if (x != y)
			{
				f[x] = y;
				ans--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
