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
int f[210][210][210],sum[210][210][210],ans[210][3];
void dp(int n,int x,int y) {
    f[x][y][0] = 0;
    for (int i = 1;i <= n; i++) {
        f[x][y][i] = f[x][y][i-1] + 1;
        if (i >= x) f[x][y][i] = min(f[x][y][i-x]+1,f[x][y][i]);
        if (i >= y) f[x][y][i] = min(f[x][y][i-y]+1,f[x][y][i]);
        sum[x][y][i] = sum[x][y][i-1] + f[x][y][i];
    }
}
int main() {
    int T,n = 200;
        for (int i = 2; i < n; i++)
            for (int j = i+1; j <= n; j++)
                dp(n,i,j);
        for (int k = 1;k <= n; k++) {
            int rec = n*(n-1)/2;
            ans[k][1] = 2;ans[k][2] = 3;
            for (int i = 2;i < k; i++)
                for (int j = i+1;j <= k; j++) {
                    if (sum[i][j][k] < rec) {
                        rec = sum[i][j][k];
                        ans[k][1] = i;ans[k][2] = j;
                    }
                }
        }
    scanf("%d\n",&T);
    while (T--) {
        scanf("%d",&n);
        printf("1 %d %d\n",ans[n][1],ans[n][2]);
    }
	return 0;
}
