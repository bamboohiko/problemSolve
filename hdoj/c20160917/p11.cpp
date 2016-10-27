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
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
typedef long long LL;
struct Edge{
    int num,to,dist,next;
};
Edge[20010] edge;
int dis[1010],n,m,k,sta[1010];
vector<int> S[1010];
bool vis[1010];
queue<int> Q;
void build(int num,int from,int to) {
    edge[++ecou] = num;edge[ecou].to = to;edge[ecou].next = head[from];head[from] = ecou;
    edge[++ecou] = num;edge[ecou].to = from;edge[ecou].next = head[to];head[to] = ecou;
}
void bfs() {
    Q.push(1);
    dis[1] = 0;vis[1] = true;
    while (!Q.empty()) {
        int s = Q.front();
        for (int i = head[s];i ;i = edge[i].next) {
            int t = edge[i].to;
            if (!vis[t]) {
                Q.push(t);
                vis[t] = true;
                dis[t] = dis[s] + 1;
            }
        }
    }
}
bool dfs(int s) {
    if (s == n) {
        S[]
    }
}
int main() {
    int t;
    while (t--) {
        memset(dis,INF,sizeof(dis));
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= m; i++) {
            scanf("%d%d%d",&from,&to,&w[i]);
            build(i,from,to);

        }
        bfs();
        dfs(1);
    }
	return 0;
}
