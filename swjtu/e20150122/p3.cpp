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
int cou[10000000 + 10],f[10000000 + 10];
stack<int> s;
void down(int x)
{
	if (!cou[x]) 
	{
		cou[x] = 1;
		f[x] = x;
	}
}
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
	int n;
	while (scanf("%d",&n) != EOF)
	{
		int ans = 1;
		memset(cou,0,sizeof(cou));
		for (int i = 1;i <= n; ++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			down(x);down(y);
			x = find(x);y = find(y);
			if (x != y)
			{
				cou[y] += cou[x];
				f[x] = y;
				ans = max(ans,cou[y]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
