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
int f[1000 + 10];
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
		int ans = 0;
		for (int i = 0;i < n; ++i) f[i] = i;
		for (int i = 1;i <= m; ++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x = find(x);y = find(y);
			if (x != y) 
				f[x] = y;
			else 
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
