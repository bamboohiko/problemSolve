#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 2000 + 10;
const int INF = 1 << 30;
struct edge{
	int from,to,dist;
	edge(int from,int to,int dist):from(from),to(to),dist(dist)	{}
	bool operator < (const edge& rhs) const {
		return dist < rhs.dist;
	}
};
struct node{
	int from,dist;
	bool operator < (const node& rhs) const {
		return dist < rhs.dist;
	}
};
struct Dijkstra{
	int n,m;
	vector<edge> edges;
	vector<int> G[maxn];
	int dis[maxn];
	int path[maxn];
	
	void init(int n)
	{
		this->n = n;
		for (int i = 1;i <= n; i++) 
			{G[i].clear();
			dis[i] = INF;
			}
		edges.clear();
	}
	
	void addedge(int from,int to,int dist)
	{
		edges.push_back((edge){from,to,dist});
		G[from].push_back(edges.size()-1);
	}
	
	int dijk(int s,int t)
	{
		priority_queue<node> Q;
		dis[s] = 0;
		Q.push((node){s,0});
		while (!Q.empty())
			{node now = Q.top();Q.pop();
			if (now.dist != dis[now.from]) continue;
			for (int i = 0;i < G[now.from].size(); i++)
				{edge& rec = edges[G[now.from][i]];
				if (dis[rec.to] > dis[now.from] + rec.dist)
					{dis[rec.to] = dis[now.from] + rec.dist;
					path[rec.to] = G[now.from][i];
					Q.push((node){rec.to,dis[rec.to]});
					} 
				}
			}
		return dis[t];
	}
}; 
Dijkstra D;
int main()
{int n,m,s,t;
	cin >> n >> m >> s >> t;
	D.init(n);
	for (int i = 1;i <= m; i++)
		{int from,to,dist;
		scanf("%d%d%d",&from,&to,&dist);
		D.addedge(from,to,dist);
		}
	cout << D.dijk(s,t) << endl;
	return 0;
}

