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
const int INF = 1e7;
int f[12][100100],a[12][100100];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF && n)
	{
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		int maxT = 0;
		for (int i = 0;i < n; i++)
		{
			int x,t;
			scanf("%d%d",&x,&t);
			a[x][t]++;
			maxT = max(maxT,t);
		}
		for (int i = 0;i <= 10; i++)
			if (i != 5) f[i][0] = -INF;
		for (int t = 1;t <= maxT; t++)
			for (int x = 0;x <= 10; x++)
			{
				f[x][t] = f[x][t-1];
				if (x != 0) f[x][t] = max(f[x][t],f[x-1][t-1]);
				if (x != 10) f[x][t] = max(f[x][t],f[x+1][t-1]);
				f[x][t] += a[x][t];
			} 
		int ans = 0;
		for (int i = 0;i <= 10; i++)
			ans = max(ans,f[i][maxT]);
		printf("%d\n",ans);
	}
	return 0;
}
