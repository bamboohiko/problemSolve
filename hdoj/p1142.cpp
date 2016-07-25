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
struct edge{
	int to,dist;
};
vector<edge> G[1010];
int dis[1010],ans[1010];
bool vis[1010];
void spfa()
{
	queue<int> Q;
	Q.push(2);
	while (!Q.empty())
	{
		int s = Q.front();Q.pop();
		for (int i = 0;i < G[s].size(); i++)
		{
			edge e = G[s][i];
			if (dis[s] + e.dist < dis[e.to])
			{
				dis[e.to] = dis[s] + e.dist;
				if (!vis[e.to])
				{
					Q.push(e.to);
					vis[e.to] = true;
				}
			}
		}
		vis[s] = false;
	}
}
int cou(int p)
{
	if (p == 2) return (ans[2] = 1);
	ans[p] = 0;
	for (int i = 0;i < G[p].size(); i++)
	{
		edge e = G[p][i];
		if (dis[p] > dis[e.to])
			if (ans[e.to] >= 0)
				ans[p] += ans[e.to];
			else
				ans[p] += cou(e.to); 
	}
	return ans[p];
}
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF && n)
	{
		int from,to,dist;
		for (int i = 1;i <= n; i++) 
		{
			G[i].clear();
			dis[i] = INF;
			ans[i] = -1;
			vis[i] = false;
		}
		dis[2] = 0;
		for (int i = 1;i <= m; i++)
		{
			scanf("%d%d%d",&from,&to,&dist);
			G[from].push_back((edge){to,dist});
			G[to].push_back((edge){from,dist});
		}
		spfa();
		printf("%d\n",cou(1));
		//for (int i = 1;i <= n; i++) cout << dis[i] << " ";cout << endl;
		//for (int i = 1;i <= n; i++) cout << ans[i] << " ";cout << endl;
	}
	return 0;
}
