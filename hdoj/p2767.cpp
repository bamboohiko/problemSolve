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
const int MAXM = 1e5 + 100;
struct Edge {
    int p,next;
};
Edge edge[MAXM];
int G[MAXN],esum = 0;
int dfn[MAXN],low[MAXN],cou = 0;
bool vis[MAXN];
int gup[MAXN],gupcou = 0,incou[MAXN],outcou[MAXN];
stack<int> S;
void build(int from,int to) {
    edge[++esum].p = to;edge[esum].next = G[from];G[from] = esum;
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
        }
    }
}
int main() {
    int t;
    int n,m;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&m);
        esum = 0;cou = 0;gupcou = 0;
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(G,0,sizeof(G));
        memset(incou,0,sizeof(incou));
        memset(outcou,0,sizeof(outcou));
        memset(vis,false,sizeof(vis));
        for (int i = 1;i <= n; i++) gup[i] = i;
        int from,to;
        for (int i = 0;i < m; i++) {
            scanf("%d%d",&from,&to);
            build(from,to);
        }
        for (int i = 1;i <= n; i++)
            if (!dfn[i]) dfs(i);
        for (int i = 1;i <= n; i++) {
            for (int j = G[i]; j; j = edge[j].next) {
                int u = gup[i],v = gup[edge[j].p];
                if (u != v) {
                    outcou[u]++;incou[v]++;
                }
            }
        }
        //for (int i = 1;i <= n; i++) cout << incou[i] << " ";cout << endl;
        //for (int i = 1;i <= n; i++) cout << outcou[i] << " ";cout << endl;
        int s1 = 0,s2 = 0;
        for (int i = 1;i <= n; i++) {
            if (gup[i] == i) {
                gupcou++;
                if (!incou[i]) s1++;
                if (!outcou[i]) s2++;
            }
        }
        if (gupcou == 1) printf("0\n");
        else printf("%d\n",max(s1,s2));
    }
	return 0;
}
