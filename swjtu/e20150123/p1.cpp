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
const int INF = 1 << 28;
int a[1010][1010];
int use[1010],dis[1010];
int main()
{
	int n,q;
	while (scanf("%d",&n) != EOF)
	{
		for (int i = 1;i <= n; i++)
			for (int j = 1;j <= n; j++)
				scanf("%d",&a[i][j]);
		scanf("%d",&q);
		for (int i = 1;i <= q; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[x][y] = a[y][x] = 0;
		}
		for (int i = 1;i <= n; i++)
			dis[i] = a[1][i];
		memset(use,0,sizeof(use));
		use[1] = 1;	
		int ans = 0;
		for (int i = 1;i < n; i++)
		{
			int rec = INF,v = 1;
			for (int i = 2;i <= n; i++)
				if (!use[i] && dis[i] < rec)
				{
					v = i;
					rec = dis[i];
				}
			ans += rec;
			use[v] = 1;
			for (int i = 2;i <= n; i++)
				if (!use[i] && a[v][i] < dis[i])
					dis[i] = a[v][i]; 
		} 
		printf("%d\n",ans);
	}
		return 0;
}

