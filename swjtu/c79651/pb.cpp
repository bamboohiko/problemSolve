#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<cmath>
using namespace std;
const int inf = 1e9+10;
struct edge{
    int to,dis;
};
vector<edge> go[1010],ba[1010];
int disgo[1010],disba[1010];
bool vis[1010];
void spfa(int n,int op,vector<edge> G[],int dis[]) {
    memset(vis,false,sizeof(vis));
    for (int i = 1;i <= n; i++) dis[i] = inf;dis[op] = 0;
    queue<int> Q;
    Q.push(op);vis[op] = true;
    while (!Q.empty()) {
        int s = Q.front();Q.pop();
        for (int i = 0;i < G[s].size(); i++) {
            edge t = G[s][i];
            if (dis[t.to] > dis[s] + t.dis) {
                dis[t.to] = dis[s] + t.dis;
                if (!vis[t.to]) {
                    Q.push(t.to);
                    vis[t.to] = true;
                }
            }
        }
        vis[s] = false;
    }
}
int main()
{
    int n,m,x;
    int from,to,dist;
    scanf("%d%d%d",&n,&m,&x);
    for (int i = 1;i <= m; i++) {
        scanf("%d%d%d",&from,&to,&dist);
        go[from].push_back((edge){to,dist});
        ba[to].push_back((edge){from,dist});
    }
    spfa(n,x,go,disgo);
    spfa(n,x,ba,disba);
    int ans = 0;
    for (int i = 1;i <= n; i++)
        ans = max(ans,disgo[i]+disba[i]);
    printf("%d\n",ans);
	return 0;
}
