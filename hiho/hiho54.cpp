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
const int MAXN = 2e4 + 100;
const int MAXM = 2e5 + 100;
struct Edge {
    int p,next;
};
int w[MAXN],dp[MAXN];
Edge edge[MAXM];
int G[MAXN],nG[MAXN],incou[MAXN],esum = 0;
int dfn[MAXN],low[MAXN],f[MAXN],cou = 0;
int gup[MAXN],gupcou = 0;
bool vis[MAXN];
stack<int> S;
void build(int from,int to) {
    edge[++esum].p = to;edge[esum].next = G[from];G[from] = esum;
}
void nbuild(int from,int to) {
    edge[++esum].p = to;edge[esum].next = nG[from];nG[from] = esum;
}
void dfs(int u) {
    dfn[u] = low[u] = ++cou;
    S.push(u);
    vis[u] = true;
    for (int i = G[u]; i ; i = edge[i].next) {
        int v = edge[i].p;
        if (!dfn[v]) {
            f[v] = u;
            dfs(v);
            low[u] = min(low[u],low[v]);
        } else if (vis[v]) {
            low[u] = min(low[u],dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        while (!S.empty()) {
            int k = S.top();S.pop();
            vis[k] = false;
            gup[k] = u;
            if (k == u) break;
            else w[u] += w[k];
        }
        gupcou++;
    }
}
int main()
{
    int n,m;
    int from,to;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&w[i]);
        gup[i] = i;
    }
    for (int i = 0;i < m; i++) {
        scanf("%d%d",&from,&to);
        build(from,to);
    }
    memset(vis,false,sizeof(vis));
    dfs(1);
    for (int u = 1;u <= n; u++) {
        for (int i = G[u]; i;i = edge[i].next) {
            int v = edge[i].p;
            if (gup[u] == gup[v]) continue;
            nbuild(gup[u],gup[v]);
            incou[gup[v]]++;
        }
    }
    int ans = dp[1] = w[1];
    queue<int> Q;
    for (int i = 1;i <= n; i++) {
        if (i != gup[i]) continue;
        if (!incou[i]) Q.push(i);
        if (!dfn[i]) w[i] = 0;
    }
    while (!Q.empty()) {
        int u = Q.front();Q.pop();
        for (int i = nG[u]; i; i = edge[i].next) {
            int v = edge[i].p;
            dp[v] = max(dp[v],dp[u] + w[v]);
            ans = max(ans,dp[v]);
            if (--incou[v] == 0) Q.push(v);
        }
    }
    printf("%d\n",ans);
	return 0;
}
