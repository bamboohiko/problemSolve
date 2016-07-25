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
struct Edge {
    int to,next;
};
Edge edge[100100];
int head[10100],esum = 0;
int dfn[10100],low[10100],gup[10100],cut = 0;
bool vis[10100];
stack<int> S;
void build(int from,int to) {
    edge[++esum].to = to;edge[esum].next = head[from];head[from] = esum;
}
void dfs(int s) {
    dfn[s] = low[s] = ++cut;
    S.push(s);
    vis[s] = true;
    for (int i = head[s]; i; i = edge[i].next) {
        int t = edge[i].to;
        if (!dfn[t]) {
            dfs(t);
            low[s] = min(low[s],low[t]);
        } else if (vis[t]) {
            low[s] = min(low[s],dfn[t]);
        }
    }
    if (low[s] == dfn[s]) {
        while (!S.empty()) {
            int t = S.top();S.pop();
            vis[t] = false;
            gup[t] = s;
            if (t == s) break;
        }
    }
}
int main() {
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF) {
        memset(head,0,sizeof(head));esum = 0;
        memset(dfn,0,sizeof(dfn));cut = 0;
        memset(vis,false,sizeof(vis));
        if (n == 0 && m == 0) break;
        int from,to;
        for (int i = 1;i <= m; i++) {
            scanf("%d%d",&from,&to);
            build(from,to);
        }
        dfs(1);
        bool ans = true;
        for (int i = 1;i <= n; i++)
            if (gup[i] != 1) {
                ans = false;
                break;
            }
        if (ans) puts("Yes");
        else puts("No");
    }
	return 0;
}
