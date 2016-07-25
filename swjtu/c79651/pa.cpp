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
const int inf = 1e9 + 10;
struct edge{
    int to,dis;
};
vector<edge> G[1010];
bool vis[1010];
int dis[1010];
int spfa(int n) {
    queue<int> Q;
    memset(vis,0,sizeof(vis));
    for (int i = 1;i <= n; i++) dis[i] = inf;
    dis[n] = 0;
    Q.push(n);
    vis[n] = true;
    while (!Q.empty()) {
        int s = Q.front();Q.pop();
        //cout << s << endl;
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
    return dis[1];
}
int main()
{
    int t,n;
    int from,to,dist;
    scanf("%d%d",&t,&n);
    for (int i = 1;i <= t; i++) {
        scanf("%d%d%d",&from,&to,&dist);
        G[from].push_back((edge){to,dist});
        G[to].push_back((edge){from,dist});
    }
    printf("%d\n",spfa(n));
	return 0;
}
