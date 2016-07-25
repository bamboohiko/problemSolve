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
priority_queue<int> G[30010];
bool vis[30010];
void dfs(int k)
{
	if (vis[k]) return;
	for (int )
}
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		memset(vis,false,sizeof(vis));
		for (int i = 1;i <= m; i++)
		{
			int from,to;
			scanf("%d%d",&from,&to);
			G[to].push(from);
		}
		int fr = 1;
		for (int i = 1;i <= n; i++)
			dfs(i);
		printf("\n");
	}
	return 0;
}
