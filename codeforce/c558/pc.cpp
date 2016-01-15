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
const int maxn = 1e5 + 100;
int sum[maxn],dis[maxn],vis[maxn],stp[maxn],a[maxn];
int main() {
    int n,m = 0;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&a[i]);
        m = max(m,a[i]);
    }
    memset(sum,0,sizeof(sum));
    for (int i = 1;i <= n; i++) {
        memset(vis,false,sizeof(vis));
        memset(stp,0,sizeof(stp));
        queue<int> Q;
        Q.push(a[i]);
        vis[a[i]] = true;
        while (!Q.empty()) {
            int u = Q.front();Q.pop();
            sum[u] += stp[u];dis[u]++;
            int v = u << 1;
            if (v <= m && !vis[v]) {
                Q.push(v);
                vis[v] = true;
                stp[v] = stp[u] + 1;
            }
            v = u >> 1;
            if (v > 0 && !vis[v]) {
                Q.push(v);
                vis[v] = true;
                stp[v] = stp[u] + 1;
            }
        }
    }
    int ans = 1e9 + 7;
    for (int i = 1;i <= m; i++) {
        if (dis[i] == n) {
            ans = min(ans,sum[i]);
        }
    }
    printf("%d\n",ans);
	return 0;
}
