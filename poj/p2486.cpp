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
const int maxn = 100 + 10;
struct Edge{
    int to,next;
};
Edge edge[maxn << 1];
int head[maxn],cnt;
int f[maxn][maxn << 1],a[maxn];
void build(int from,int to) {
    edge[++cnt].to = to;edge[cnt].next = head[from];head[from] = cnt;
    edge[++cnt].to = from;edge[cnt].next = head[to];head[to] = cnt;
}
void dfs(int s,int fa,int p) {
    for (int i = head[s];i ;i = edge[i].next) {
        int t = edge[i].to;
        if (t == fa) continue;
        dfs(t,s,p-1);
        for (int j = p;j >= 1; j--)
            for (int k = 1;k <= j; k++)
                f[s][j] = max(f[s][j],f[s][j-k] + f[t][k] + 2);
    }
    for (int i = p;i >= 1; i--)
        f[s][i] = f[s][i-1] + a[s];
}
int main() {
    int n,p;
    while (scanf("%d%d",&n,&p) != EOF) {
        memset(head,0,sizeof(head));cnt = 0;
        memset(f,0,sizeof(f));
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        int from,to;
        for (int i = 1;i < n; i++) {
            scanf("%d%d",&from,&to);
            build(from,to);
        }
        dfs(1,0,p);
        printf("%d\n",f[1][p][0]);
    }
	return 0;
}
