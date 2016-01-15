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
bool vis[2010][2010];
double f[2010][2010],p;
int h,a[2010];
double dfs(int l,int r) {
    if (l > r) return 0;
    if (l == r) return 1;
    if (vis[l][r]) return f[l][r];
    f[l][r] = 0.5*p*dfs(l+1,r) + 0.5*(1-p)*dfs(l,r-1);
    int i;
    for (i = l;i < r && a[i+1] - a[i] < h; i++) ; f[l][r] += 0.5*(1-p)*dfs(i+1,r);
    for (i = r;i > l && a[i] - a[i-1] < h; i--) ; f[l][r] += 0.5*p*dfs(l,i-1);
    f[l][r] += 1;
    vis[l][r] = true;
    printf("%d %d %lf\n",l,r,f[l][r]);
    return f[l][r];
}
int main() {
    int n;
    scanf("%d%d%lf",&n,&h,&p);
    for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
    printf("%.9lf\n",dfs(1,n));
	return 0;
}
