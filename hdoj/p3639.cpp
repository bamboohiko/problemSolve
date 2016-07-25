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
const int MAXN = 5e3 + 100;
const int MAXM = 6e4 + 100;
struct Edge{
    int p,next;
};
Edge edge[MAXM];
int G[MAXN],nG[MAXN],esum = 0;
int dfn[MAXN],low[MAXN],cou = 0;
int gup[MAXN],gupcou = 0,incou[MAXN],dp[MAXN];
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
    for (int i = G[u]; i;i = edge[i].next) {
        int v = edge[i].p;
        if (!dfn[v]) {
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
            else dp[u]++;
        }
        gupcou++;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        esum = 0,cou = 0,gupcou = 0;
        memset(G,0,sizeof(G));memset(nG,0,sizeof(nG));
        memset(dfn,0,sizeof(dfn));memset(low,0,sizeof(low));
        memset(incou,0,sizeof(incou));
        memset(vis,false,sizeof(vis));
        int n,m;
        int from,to;
        scanf("%d%d",&n,&m);
        for (int i = 0;i < n; i++) {
            gup[i] = i;dp[i] = 1;
        }
        for (int i = 0;i < m; i++) {
            scanf("%d%d",&from,&to);
            build(from,to);
        }
        for (int i = 0;i < n; i++)
            if (!dfn[i]) dfs(i);
        for (int i = 0;i < n; i++) {
            for (int j = G[i]; j; j = edge[j].next) {
                int u = gup[i],v = gup[edge[j].p];
                if (u == v) continue;
                nbuild(u,v);
                incou[v]++;
            }
        }
        queue<int> Q;
        for (int i = 0;i < gupcou; i++)
            if (!incou[i]) Q.push(i);
        int ans = 0;
        while (!Q.empty()) {
            int u = Q.front();Q.pop();
            for (int i = nG[u]; i; i = edge[i].next) {
                int v = edge[i].p;
                dp[v] += dp[u];
                if (--incou[v] == 0) Q.push(v);
            }
            if (dp[u] > ans) ans = dp[u];
        }
        printf("Case %d: %d\n",ca,ans-1);
        bool fr = true;
        for (int i = 0;i < n; i++) {
            if (dp[gup[i]] == ans)
                if (fr) {
                    printf("%d",i);
                    fr = false;
                } else {
                    printf(" %d",i);
                }
        }
        printf("\n");
    }
	return 0;
}
