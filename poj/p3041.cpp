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
struct Edge {
    int to,next;
};
Edge edge[10100];
int head[510],cou = 0;
int f[510];
bool vis[510];
void build(int x,int y) {
    edge[++cou].to = y;edge[cou].next = head[x];head[x] = cou;
}
int dfs(int s) {
    for (int i = head[s];i != -1;i = edge[i].next) {
        int t = edge[i].to;
        if (!vis[t]) {
            vis[t] = true;
            if (f[t] == 0 || dfs(f[t])) {
                f[t] = s;
                return true;
            }
        }
    }
    return false;
}
int main() {
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF) {
        memset(head,-1,sizeof(head));cou = 0;
        int x,y;
        for (int i = 1;i <= m; i++) {
            scanf("%d%d",&x,&y);
            build(x,y);
        }
        int ans = 0;
        memset(f,0,sizeof(f));
        for (int i = 1;i <= n; i++) {
            memset(vis,0,sizeof(vis));
            if (dfs(i)) ans++;
        }
        printf("%d\n",ans);
    }
	return 0;
}
