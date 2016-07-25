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
#define INF 0x3f3f3f3f
const int maxn = 150 + 10;
struct Edge{
    int to,next;
};
Edge edge[maxn << 1];
int head[maxn],cnt,n,p,ans;
int f[200][200],sum[200];
void build(int from,int to) {
    edge[++cnt].to = to;edge[cnt].next = head[from];head[from] = cnt;
}
int dfs(int s,int fa) {
    f[s][1] = 0;sum[s] = 1;
    for (int eg = head[s];eg ;eg = edge[eg].next) {
        int t = edge[eg].to;
        dfs(t,s);
        f[s][1]++;
        sum[s] += sum[t];
    }
    for (int eg = head[s];eg ;eg = edge[eg].next) {
        int t = edge[eg].to;
        for (int j = sum[s];j >= 1;j--)
            for (int i = 1;i <= j; i++)
                f[s][j] = min(f[s][j],f[s][j-i]+f[t][i]-1);
    }
    if (sum[s] >= p)
        ans = min(ans,f[s][p] + (fa?1:0));
}
int main() {
    while (scanf("%d%d",&n,&p) != EOF) {
        memset(head,0,sizeof(head));cnt = 0;
        memset(f,INF,sizeof(f));
        memset(sum,0,sizeof(sum));
        int from,to;
        for (int i = 1;i < n; i++) {
            scanf("%d%d",&from,&to);
            build(from,to);
        }
        ans = INF;
        dfs(1,0);
        printf("%d\n",ans);
    }
	return 0;
}
