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
const int maxn = 50;
const int maxm = 2e6;
int n,m,a[maxn];
LL f[maxn][maxm];
bool vis[maxn][maxm];
LL dfs(int k,int v) {
    if (vis[k][v]) return f[k][v];
    if (k > n) {
        if (v >= m) return 1;
        else return 0;
    }
    f[k][v] = dfs(k+1,v)+dfs(k+1,v^a[k]);
    vis[k][v] = true;
    return f[k][v];
}
int main() {
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t;ca++) {
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        printf("Case #%d: %lld\n",ca,dfs(1,0));
    }
	return 0;
}
