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
int a[110][110];
int use[110],dis[110];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF && n)
	{
		for (int i = 1;i <= n*(n-1)/2; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			scanf("%d",&a[x][y]);
			a[y][x] = a[x][y];
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

