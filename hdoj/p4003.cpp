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
struct Edge{
    int to,next,dis;
};
Edge edge[20010];
int head[10010],cnt;
int sum[10010],f[10010][20];
void build(int from,int to,int dis) {
    edge[++cnt].to = to;edge[cnt].dis = dis;edge[cnt].next = head[from];head[from] = cnt;
}
int dfs(int s,int k,int fa) {
    for (int i = head[s];i ;i = edge[i].next) {
        int t = edge[i].to,dis = edge[i].dis;
        if (t == fa) continue;
        dfs(t,k,s);
        for (int j = k;j >= 0; j--) {
            f[s][j] += f[t][0] + dis*2;
            for (int x = 1;x <= j; x++)
                f[s][j] = min(f[s][j],f[s][j-x] + f[t][x] + x*dis);
        }
    }
    //for (int i = 1;i <= k; i++) cout << f[s][k] << " ";cout << endl;
    return f[s][k];
}
int main() {
    int n,s,k;
    while (scanf("%d%d%d",&n,&s,&k) != EOF) {
        memset(f,0,sizeof(f));
        memset(head,0,sizeof(head));
        memset(sum,0,sizeof(sum));
        cnt = 0;
        int from,to,dis;
        for (int i = 1;i < n; i++) {
            scanf("%d%d%d",&from,&to,&dis);
            build(from,to,dis);
            build(to,from,dis);
        }
        printf("%d\n",dfs(s,k,0));
    }
	return 0;
}
