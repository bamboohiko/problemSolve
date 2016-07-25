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
Edge edge[MAXM];
int G[MAXN],esum = 0;
int dfn[MAXN],low[MAXN],f[MAXN],cou = 0;
int gup[MAXN],gupcou = 0;
stack<int> S;
void build(int a,int b) {
    edge[++esum].p = a;edge[esum].next = G[b];G[b] = esum;
    edge[++esum].p = b;edge[esum].next = G[a];G[a] = esum;
}
int find(int k) {
    stack<int> Sf;
    while (gup[k] != k) {
        Sf.push(k);
        k = gup[k];
    }
    while (!Sf.empty()) {
        int p = Sf.top();Sf.pop();
        gup[p] = k;
    }
    return k;
}
void dfs(int u) {
    dfn[u] = low[u] = ++cou;
    S.push(u);
    for (int i = G[u];i ;i = edge[i].next) {
        int v = edge[i].p;
        if (v == f[u]) continue;
        if (!dfn[v]) {
            f[v] = u;
            dfs(v);
            low[u] = min(low[u],low[v]);
        } else {
            low[u] =  min(low[u],dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        while (!S.empty()) {
            int k = S.top();S.pop();
            int a = find(k),b = find(u);
            if (a != b)
                if (a > b) gup[a] = b;
                else gup[b] = a;
            if (k == u) break;
        }
        gupcou++;
    }
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
    for (int i = 1;i <=  n; i++) gup[i] = i;
    dfs(1);
    printf("%d\n",gupcou);
    for (int i = 1;i < n; i++) printf("%d ",find(i));
    printf("%d\n",gup[n]);
	return 0;
}
