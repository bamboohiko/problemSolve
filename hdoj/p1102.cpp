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
const int INF = 2e9 + 7;
struct point{
	int to,dist;
	bool operator < (const point &rhs) const
	{
		return dist > rhs.dist;
	}
};
int n,m,dis[1010],edge[1010][1010];
bool vis[1010];
int prim()
{
	int ans = 0;
	priority_queue<point> Q;
	for (int i = 1;i <= n; i++) vis[i] = false;
	for (int i = 1;i <= n; i++) dis[i] = INF;dis[1] = 0;
	Q.push((point){1,0});
	while (!Q.empty())
	{
		point s = Q.top();Q.pop();
		if (vis[s.to]) continue;
		vis[s.to] = true;
		//cout << s.to << endl;
		for (int i = 1;i <= n; i++)
		{
			if (!vis[i] && dis[i] > edge[s.to][i])
			{
				dis[i] = edge[s.to][i];
				Q.push((point){i,dis[i]});
				//cout << i << endl;
			}
		}
		ans += dis[s.to];
	}
	return ans;
}
int main()
{
	int x,y;
	while (scanf("%d",&n) != EOF)
	{
		for (int i = 1;i <= n; i++)
			for (int j = 1;j <= n; j++)
				scanf("%d",&edge[i][j]);
		scanf("%d",&m);
		for (int i = 1;i <= m; i++)
		{
			scanf("%d%d",&x,&y);
			edge[x][y] = edge[y][x] = 0;
		}
		printf("%d\n",prim());
	}
	return 0;
}
