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
int sum[110],a[110];
int f[110][110],vis[110][110];
int dfs(int i,int j) {
    if (vis[i][j]) return f[i][j];
    int m = 0;
    for (int k = i;k < j; k++) m = min(m,dfs(i,k));
    for (int k = j;k > i; k--) m = min(m,dfs(k,j));
    f[i][j] = sum[j] - sum[i-1] - m;
    vis[i][j] = true;
    return f[i][j];
}
int main() {
    int n;
    while (scanf("%d",&n) != EOF && n) {
        memset(vis,0,sizeof(vis));
        for (int i = 1;i <= n; i++) {
            scanf("%d",&a[i]);
            sum[i] = sum[i-1] + a[i];
        }
        printf("%d\n",2*dfs(1,n)-sum[n]);
    }
	return 0;
}
