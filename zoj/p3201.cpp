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
struct Edge{
    int to,next;
};
Edge edge[210];
int head[110],cnt;
int f[110][110],p[110];
void build(int from,int to) {
    edge[++cnt].to = to;edge[cnt].next = head[from];head[from] = cnt;
    edge[++cnt].to = from;edge[cnt].next = head[to];head[to] = cnt;
}
void dfs(int s,int fa,int m) {
    for (int i = head[s];i ;i = edge[i].next) {
        int t = edge[i].to;
        if (t == fa) continue;
        dfs(t,s,m);
        for (int j = m;j >= 0;j--)
            for (int i = 1;i <= j; i++)
                f[s][j] = max(f[s][j],f[s][j-i]+ f[t][i]);
    }
    for (int j = m;j >= 1; j--)
        f[s][j] = f[s][j-1] + p[s];
}
int main() {
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF) {
        memset(f,0,sizeof(f));
        memset(head,0,sizeof(head));cnt = 0;
        for (int i = 0;i < n; i++) scanf("%d",&p[i]);
        int from,to;
        for (int i = 1;i < n; i++) {
            scanf("%d%d",&from,&to);
            build(from,to);
        }
        dfs(0,-1,m);
        int ans = 0;
        for (int i = 0;i < n; i++)
            ans = max(ans,f[i][m]);
        printf("%d\n",ans);
    }
	return 0;
}


