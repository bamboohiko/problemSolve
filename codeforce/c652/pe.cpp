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
const int maxn = 5e5 + 100;
struct Edge {
    int to,dis,next;
};
Edge edge[6*maxn];
int head[maxn],esum = 0;
int dfn[maxn],low[maxn],f[maxn],cou = 0;
int gup[maxn],can[maxn];
bool vis[maxn];
stack<int> S;
void build(int from,int to,int dis) {
    edge[++cou].to = to;edge[cou].dis = dis;
    edge[cou].next = head[from];head[from] = cou;
}
int find(int k) {
    stack<int> S;
    while (gup[k] != k) {
        S.push(k);
        k = gup[k];
    }
    while (!S.empty()) {
        int p = S.top();S.pop();
        gup[p] = k;
    }
    return k;
}
int dfs(int u) {
    dfn[u] = low[u] = ++cou;
    S.push(u);
    for (int i = head[u];i != -1;i = edge[i].next) {
        int v = edge[i].to;
        if (v == f[u]) continue;
        if (!dfn[v]) {
            f[v] = u;
            dfs(v);
            low[u] = min(low[u],low[v]);
        } else  low[u] = min(low[u],dfn[v]);
    }
    if (dfn[u] == low[u]) {
        while (!S.empty()) {
            int t = S.top();S.pop();
            int a = find(t),b = find(u);
            if (a > b) gup[a] = b;
            if (b > a) gup[b] = a;
            if (t == u) break;
        }
    }
}
int dfs2(int u,int t,int k) {
    if (u == t) return k;
    for (int i = head[u];i != -1;i = edge[i].next) {
        int v = find(edge[i].to);
        if (!vis[v]) {
            int nk = k;
            if (edge[i].dis || can[v]) nk = 1;
            vis[v] = true;
            if (dfs2(v,t,nk)) return true;
        }
    }
    return false;
}
int main() {
    int n,m,s,t;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; i++) gup[i] = i;
    memset(head,-1,sizeof(head));
    int from,to,dis;
    for (int i = 1;i <= m; i++) {
        scanf("%d%d%d",&from,&to,&dis);
        build(from,to,dis);
        build(to,from,dis);
    }
    scanf("%d%d",&s,&t);
    dfs(s);
    //for (int i = 1;i <= n; i++) cout << (find(i)) << endl;
    for (int u = 1;u <= m; u++) {
        int a = find(u);
        if (a == u) continue;
        for (int i = head[u];i != -1;i = edge[i].next) {
            int b = find(edge[i].to);
            if (b == a) {
                if (edge[i].dis) can[a] = 1;
                continue;
            }
            build(a,b,edge[i].dis);
        }
    }
    s = find(s);t = find(t);vis[s] = true;
    if (dfs2(s,t,can[s])) puts("YES");
    else puts("NO");
	return 0;
}

