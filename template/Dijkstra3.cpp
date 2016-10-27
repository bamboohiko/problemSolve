#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 2000 + 10;
const int INF = 1 << 25;
struct edge{
	int to,dist;
};
struct node{
	int from,dist;
	bool operator < (const node& rhs) const{
		return dist < rhs.dist;
	}
};
vector<edge> G[maxn];
int path[maxn];
int dis[maxn];
int dijk(int s,int t)
{
	priority_queue<node> Q;
	dis[s] = 0;
	Q.push((node){s,0});
	while (!Q.empty())
		{node now = Q.top();Q.pop();
		//cout << now.from << endl;
		if (now.dist != dis[now.from]) continue;
		for (int i = 0;i < G[now.from].size(); i++)
			{edge& rec = G[now.from][i];
			//printf("%d %d\n",rec.to,rec.dist);
			if (dis[rec.to] > dis[now.from] + rec.dist)
				{dis[rec.to] = dis[now.from] + rec.dist;
				path[rec.to] = now.from;
				Q.push((node){rec.to,dis[rec.to]});
				}
			}
		}
	return dis[t];
}
void dfs(int s,int t)
{
	if (path[t] != s) dfs(s,path[t]);
	cout << path[t] << " ";
}
int main()
{int n,m,s,t;
	cin >> n >> m >> s >> t;
	for (int i = 1;i <= n; i++) dis[i] = INF;
	for (int i = 1;i <= m; i++)	
		{int from,to,dist;
		scanf("%d%d%d",&from,&to,&dist);
		G[from].push_back((edge){to,dist});
		}
	cout << dijk(s,t) << endl;
	dfs(s,t);
	cout << t << endl;
	return 0;
}
