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
typedef long long LL;
const int maxn = 1e6 + 10;
struct Edge {
    int to,next;
};
Edge edge[maxn << 1];
int head[maxn],cnt;
LL ans,sum;
LL sz[maxn],v[maxn];
void build(int from,int to) {
    edge[++cnt].to = to;edge[cnt].next = head[from];head[from] = cnt;
    edge[++cnt].to = from;edge[cnt].next = head[to];head[to] = cnt;
}
void dfs(int s,int fa) {
    for (int i = head[s];i ; i = edge[i].next) {
        int t = edge[i].to;
        if (t == fa) continue;
        dfs(t,s);
        sz[s] += sz[t];
    }
    sz[s] += v[s];
    LL sav = sz[s]+sz[s]-sum;
    ans = min(ans,(sav > 0?sav:-sav));
}
int main() {
    int n,m,ca = 0;
    while (scanf("%d%d",&n,&m) != EOF) {
        memset(head,0,sizeof(head));cnt = 0;
        memset(sz,0,sizeof(sz));
        sum = 0;
        if (n == 0 && m == 0) break;
        for (int i = 1;i <= n; i++) {
            scanf("%lld",&v[i]);
            sum += v[i];
        }
        ans = sum;
        int from,to;
        for (int i = 1;i <= m; i++) {
            scanf("%d%d",&from,&to);
            build(from,to);
        }
        dfs(1,0);
        printf("Case %d: %lld\n",++ca, ans);
    }
	return 0;
}

