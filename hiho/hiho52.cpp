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
struct Edge{
    int p,next;
};
Edge edge[MAXM];
int G[MAXN],esum = 0;
int dfn[MAXN],low[MAXN],f[MAXN],cou = 0;
vector<int> point;
vector<Edge> bridge;
void build(int a,int b) {
    edge[++esum].p = b;edge[esum].next = G[a];G[a] = esum;
    edge[++esum].p = a;edge[esum].next = G[b];G[b] = esum;
}
void dfs(int u) {
    bool add = false;
    dfn[u] = low[u] = ++cou;
    int chd = 0;
    for (int i = G[u];i;i = edge[i].next) {
        int v = edge[i].p;
        if (!dfn[v]) {
            chd++;
            f[v] = u;dfs(v);
            low[u] = min(low[u],low[v]);
            if (!add && f[u] == 0 && chd > 1) {point.push_back(u);add = true;}
            if (!add && f[u] && low[v] >= dfn[u]) {point.push_back(u);add = true;}
            if (low[v] > dfn[u]) bridge.push_back((Edge){min(u,v),max(u,v)});
        } else if (v != f[u]) {
            low[u] = min(low[u],dfn[v]);
        }
    }
}
bool cmp(Edge a,Edge b) {
    if (a.p == b.p) return a.next < b.next;
    return a.p < b.p;
}
int main()
{
    int n,m;
    int from,to;
    scanf("%d%d",&n,&m);
    for (int i = 0;i < m; i++) {
        scanf("%d%d",&from,&to);
        build(from,to);
    }
    dfs(1);
    sort(point.begin(),point.end());
    sort(bridge.begin(),bridge.end(),cmp);
    if (point.size()) {
        printf("%d",point[0]);
        for (int i = 1;i < point.size(); i++)
            printf(" %d",point[i]);
        printf("\n");
    } else {
        printf("Null\n");
    }
    for (int i = 0;i < bridge.size(); i++) {
        printf("%d %d\n",bridge[i].p,bridge[i].next);
    }
	return 0;
}
