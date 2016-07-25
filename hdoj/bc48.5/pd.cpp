#include<iostream>
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
const int maxn = 1e4;
const int maxm = 2e5 + 100;
struct Edge {
    int p,next;
};
Edge edge[maxm];
int G[maxn],esum;
bool vis[maxn];
int v[maxn][2],f[maxn];
void build(int from,int to) {
    edge[++esum].p = to;edge[esum].next = G[from];G[from] = esum;
    edge[++esum].p = from;edge[esum].next = G[to];G[to] = esum;
}
void dfs(int k,int num,int rec) {
    vis[k] = true;
    v[rec][num]++;
    for (int i = G[k];i; i = edge[i].next) {
        int t = edge[i].p;
        if (!vis[t]) dfs(t,1-num,rec);
    }
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(G,0,sizeof(G));
        memset(f,0,sizeof(f));
        memset(vis,false,sizeof(vis));
        memset(v,0,sizeof(v));
        esum = 0;
        int n,m;
        int from,to;
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= m; i++) {
            scanf("%d%d",&from,&to);
            build(from,to);
        }
        int cou = 0;
        for (int i = 1;i <= n; i++) {
            if (vis[i]) continue;
            dfs(i,0,cou);
            //cout << v[cou][0] << " " << v[cou][1] << endl;
            cou++;
        }
        f[0] = 1;
        for (int k = 0;k < cou; k++)
            for (int i = n;i >= 0; i--)
                for (int j = 0;j <= 1; j++) {
                    if (i < v[k][j]) break;
                    if (f[i - v[k][j]]) f[i] = 1;
                }
        for (int i = n/2; i <= n; i++)
            if (f[i]) {
                printf("%d\n",i*(n-i)-m);
                break;
            }
    }
	return 0;
}

