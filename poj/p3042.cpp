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
const int inf = 1e9 + 7;
int a[1010],f[1010][1010][2];
bool vis[1010][1010][2];
int n,l;
int dfs(int l,int r,int k) {
    if (l-(1-k) < 1 && r+k > n) return 0;
    if (vis[l][r][k]) return f[l][r][k];
    f[l][r][k] = inf;
    if (k == 0) {
        if (l > 1) f[l][r][k] = min(f[l][r][k],dfs(l-1,r,0)+(a[l]-a[l-1])*(l+n-r));
        if (r <= n) f[l][r][k] = min(f[l][r][k],dfs(l-1,r,1)+(a[r]-a[l])*(l+n-r));
    } else {
        if (r < n) f[l][r][k] = min(f[l][r][k],dfs(l,r+1,1)+(a[r+1]-a[r])*(l+n-r));
        if (l >= 1) f[l][r][k] = min(f[l][r][k],dfs(l,r+1,0)+(a[r]-a[l])*(l+n-r));
    }
    //printf("%d %d %d %d\n",l,r,k,f[l][r][k]);
    vis[l][r][k] = true;
    return f[l][r][k];
}
int main() {
    while (scanf("%d%d",&n,&l) != EOF) {
        memset(vis,0,sizeof(vis));
        for (int i = 1;i <= n; i++) {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        int ans = 0;
        if (l <= a[1]) {
            a[0] = l;
            for (int i = 1;i <= n;i++) ans += (a[i]-a[i-1])*(n-i+1);
        } else if (l >= a[n]) {
            a[n+1] = l;
            for (int i = n;i >= 1;i--) ans += (a[i+1]-a[i])*i;
        } else {
            int k = lower_bound(a+1,a+n+1,l) - a;
            ans = min(dfs(k-1,k,0)+(l-a[k-1])*n,dfs(k-1,k,1)+(a[k]-l)*n);
        }
        printf("%d\n",ans);
    }
	return 0;
}
