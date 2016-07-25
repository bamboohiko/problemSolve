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
const int maxn = 110;
int n,k,f[maxn][maxn],a[maxn][maxn];
int dfs(int x,int y) {
    if (f[x][y]) return f[x][y];
    for (int i = x-k;i <= x+k; i++)
        if (i >= 0 && i < n && a[x][y] < a[i][y]) f[x][y] = max(f[x][y],dfs(i,y));
    for (int i = y-k;i <= y+k; i++)
        if (i >= 0 && i < n && a[x][y] < a[x][i]) f[x][y] = max(f[x][y],dfs(x,i));
    f[x][y] += a[x][y];
    return f[x][y];
}
int main() {

    while (scanf("%d%d",&n,&k) != EOF) {
        if (n == -1 && k == -1) break;
        memset(f,0,sizeof(f));
        for (int i = 0;i < n; i++)
            for (int j = 0;j < n; j++) scanf("%d",&a[i][j]);
        printf("%d\n",dfs(0,0));
    }
	return 0;
}
