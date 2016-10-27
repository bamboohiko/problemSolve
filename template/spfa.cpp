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
const int INF = 1e9 + 7;
struct e{
	int to,dist;
};
vector<e> edge;
vector<int> G[100100];
bool pos[100100];
int dis[100100];
int spfa(int s,int t)
{
	queue<int> Q;
	Q.push(s);dis[s] = 0;
	while (!Q.empty())
	{
		int p = Q.front();Q.pop();pos[p] = false;
		for (int i = 0;i < G[p].size(); i++)
		{
			e k = edge[G[p][i]];
			if (dis[p] + k.dist < dis[k.to])
			{
				dis[k.to] = dis[p] + k.dist;
				if (!pos[k.to])
				{
					Q.push(k.to);
					pos[k.to] = true;
				}
			}
		}
	}
	return dis[t];
}
int main()
{
	int n,m,s,t;
	int from,to,dist;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for (int i = 1;i <= m; i++)
	{
		scanf("%d%d%d",&from,&to,&dist);
		edge.push_back((e){to,dist});G[from].push_back(edge.size()-1);
		edge.push_back((e){from,dist});G[to].push_back(edge.size()-1);
	}
	for (int i = 1;i <= n; i++) dis[i] = INF;
	cout << spfa(s,t) << endl;
	return 0;
}
