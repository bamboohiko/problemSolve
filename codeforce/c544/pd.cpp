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
vector<int> G[3010];
int dis[3010][3010];
bool vis[3010];
void build(int x,int y) {
	G[x].push_back(y);
	G[y].push_back(x);
}
void bfs(int k) {
	memset(vis,0,sizeof(vis));
	queue<int> Q;
	Q.push(k);vis[k] = true;
	while (!Q.empty()) {
		int s = Q.front();Q.pop();
		for (int i = 0;i < G[s].size(); i++) {
			int t = G[s][i];
			if (!vis[t]) {
				vis[t] = true;
				Q.push(t);
				dis[k][t] = dis[k][s] + 1;
			}
		}
	}
}
int main()
{
	int n,m;
	int x,y;
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m; i++) {
		scanf("%d%d",&x,&y);
		build(x,y);
	}
	for (int i = 1;i <= n; i++) bfs(i);
//	for (int i = 1;i <= n; i++) {
//		for (int j = 1;j <= n; j++) cout << dis[i][j] << " ";
//		cout << endl;
//	}
	int x1,y1,len1,x2,y2,len2;
	scanf("%d%d%d",&x1,&y1,&len1);
	scanf("%d%d%d",&x2,&y2,&len2);
	int ans = m+1;
	if (dis[x1][y1] <= len1 && dis[x2][y2] <= len2) ans = min(ans,dis[x1][y1] + dis[x2][y2]);
	for (int i = 1;i <= n; i++)
		for (int j = 1;j <= n; j++) {
			int t1 = min(dis[x1][j] + dis[i][y1],dis[x1][i] + dis[j][y1]);
			int t2 = min(dis[x2][j] + dis[i][y2],dis[x2][i] + dis[j][y2]);
			if (t1 + dis[i][j] <= len1 && t2 + dis[i][j] <= len2) {
				ans = min(ans,t1 + t2 + dis[i][j]);
			}
		}
	printf("%d\n",m-ans);
	return 0;
}
