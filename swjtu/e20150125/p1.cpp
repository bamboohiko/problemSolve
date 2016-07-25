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
int n,a[50100];
int lowbit(int x)
{
	return x & (-x);
}
void add(int p,int x)
{
	while (p <= n)
	{
		a[p] += x;
		p += lowbit(p);
	}
}
int sum(int p)
{
	int ans = 0;
	while (p >= 1)
	{
		ans += a[p];
		p -= lowbit(p);
	}
	return ans;
}
int main()
{
	int t,c = 0;
	scanf("%d",&t);
	while (++c <= t)
	{
		printf("Case %d:\n",c);
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for (int i = 1;i <= n; i++)
		{
			int x;
			scanf("%d",&x);
			add(i,x);
		}
		char s[10]; int x,y; 
		while (scanf("%s",s) != EOF)
		{
			if (s[0] == 'E') break;
			scanf("%d%d",&x,&y);
			if (s[0] == 'A') add(x,y);
			if (s[0] == 'S') add(x,-y);
			if (s[0] == 'Q') printf("%d\n",sum(y) - sum(x-1));
		}
	}
	return 0;
}

