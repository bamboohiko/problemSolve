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
Edge edge[110];
int head[110],cnt;
int f[110][110],v[110],p[110];
void build(int from,int to) {
    edge[++cnt].to = to;edge[cnt].next = head[from];head[from] = cnt;
    edge[++cnt].to = from;edge[cnt].next = head[to];head[to] = cnt;
}
void dfs(int s,int fa,int m) {
    for (int i = head[s];i ;i = edge[i].next) {
        int t = edge[i].to;
        if (t == fa) continue;
        dfs(t,s,m - v[s]);
        for (int j = m-v[s];j >= 1; j--)
            for (int i = max(v[t],1);i <= j; i++)
                f[s][j] = max(f[s][j],f[s][j-i] + f[t][i]);
    }
    for (int j = m;j >= v[s];j--)
        f[s][j] = f[s][j-v[s]] + p[s];
}
int main() {
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF) {
        if (n == -1 && m == -1) break;
        memset(head,0,sizeof(head));cnt = 0;
        memset(f,0,sizeof(f));
        for (int i = 1;i <= n; i++) {
            scanf("%d%d",&v[i],&p[i]);
            v[i] = v[i]/20 + ((v[i]%20)?1:0);
        }
        int from,to;
        for (int i = 1;i < n; i++) {
            scanf("%d%d",&from,&to);
            build(from,to);
        }
        dfs(1,0,m);
        if (m == 0) printf("%d\n",0);
        else printf("%d\n",f[1][m]);
    }
	return 0;
}

