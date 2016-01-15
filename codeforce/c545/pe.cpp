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
const int INF = 1e9+7;
struct edge {
	int to,dist,num;
};
struct node{
	int from,dist;
	bool operator < (const node& rhs) const{
		return dist > rhs.dist;
	}
};
vector<edge> G[300100];
vector<int> ans;
edge path[300100];
int dis[300100];
long long sum = 0;
bool vis[300100];
void build(int from,int to,int dist,int num) {
	G[from].push_back((edge){to,dist,num});
	G[to].push_back((edge){from,dist,num});
}
void dijk(int k,int n) {
	priority_queue<node> Q;
	memset(vis,0,sizeof(vis));
	dis[k] = 0;
	Q.push((node){k,0});
	while (!Q.empty()) {
		node s = Q.top();Q.pop();
		if (vis[s.from]) continue;
		vis[s.from] = true;
//		cout << s.from << ":1"<< endl;
//		sum += dis[s.from];
		for (int j = 0;j < G[s.from].size(); j++) {
			edge& t = G[s.from][j];
			if (!vis[t.to] && dis[t.to] >= dis[s.from] + t.dist) {
				dis[t.to] = dis[s.from] + t.dist;
				//cout << t.to << " " << dis[t.to]<< endl;
				path[t.to] = (edge){s.from,t.dist,t.num};
				Q.push((node){t.to,dis[t.to]});
			}
		}
	}
}
void dfs(int k) {
	sum += path[k].dist;
	ans.push_back(path[k].num);
	vis[k] = true;
	if (!vis[path[k].to]) dfs(path[k].to);
}
int main()
{
	int n,m,u;
	scanf("%d%d",&n,&m);
	int from,to,dist;
	for (int i = 1;i <= m; i++) {
		 scanf("%d%d%d",&from,&to,&dist);
		 build(from,to,dist,i);
	}
	for (int i = 1;i <= n; i++) dis[i] = INF;
	scanf("%d",&u);
	dijk(u,n);
	memset(vis,0,sizeof(vis));
	vis[u] = true;
	for (int i = 1;i <= n; i++)
		if (!vis[i]) dfs(i);
	sort(ans.begin(),ans.end());
	printf("%d\n%d",sum,ans[0]);
	for (int i = 1;i < ans.size(); i++)
		printf(" %d",ans[i]);
	printf("\n");
	return 0;
}
