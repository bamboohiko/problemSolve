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
double f[1010][1010];
bool vis[1010][1010];
double dfs(int n,int m) {
    if (n == 0) return 0;
    if (m == 0) return 1;
    if (vis[n][m]) return f[n][m];
    if (m >= 2) f[n][m] += 1.0*n/(n+m-2)*dfs(n-1,m-2);
    if (m >= 3) f[n][m] += 1.0*(m-2)/(n+m-2)*dfs(n,m-3);
    f[n][m] *= 1.0*m/(n+m)*(m-1)/(n+m-1);
    f[n][m] += 1.0*n/(n+m);
    vis[n][m] = true;
    //printf("%d %d %lf\n",n,m,f[n][m]);
    return f[n][m];
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%.9lf\n",dfs(n,m));
	return 0;
}
