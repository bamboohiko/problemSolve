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
const int maxn = 210;
int maze[maxn][maxn];
int gap[maxn],dis[maxn],pre[maxn],cur[maxn];
int sap(int s,int t,int num) {
    memset(cur,0,sizeof(cur));
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    int u = pre[s] = s,maxflow = 0,aug = -1;
    gap[0] = num;
    while (dis[s] < num) {
        loop:
        for (int v = cur[u]; v < num; v++)
            if (maze[u][v] && dis[u] == dis[v] + 1) {
                if (aug == -1 || aug > maze[u][v]) aug = maze[u][v];
                pre[v] = u;
                u = cur[u] = v;
                if (v == t) {
                    maxflow += aug;
                    for (u = pre[u]; v != s; v = u,u = pre[u]) {
                        maze[u][v] -= aug;
                        maze[v][u] += aug;
                    }
                    aug = -1;
                }
                goto loop;
            }
        int mindis = num -1;
        for (int v = 0; v < num; v++)
            if (maze[u][v] && mindis > dis[v]) {
                cur[u] = v;
                mindis = dis[v];
            }
        if ((--gap[dis[u]]) == 0) break;
        gap[dis[u] = mindis+1]++;
        u = pre[u];
    }
    return maxflow;
}
int main() {
    int n,m;
    int from,to,flw;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d",&from,&to,&flw);
        if (maze[from][to] < 0) continue;
        maze[from][to] += flw;
        maze[to][from] = -maze[from][to];
    }
    cout << sap(1,m,m+1) << endl;
    return 0;
}
