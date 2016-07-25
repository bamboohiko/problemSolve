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
int a[1010][1010],f[1010][1010];
int main() {
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF) {
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= m; j++)
                scanf("%d",&a[i][j]);
        memset(f,INF,sizeof(f));f[1][1] = 0;
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= m; j++) {
                if (i == 1 && j == 1) continue;
                if ((i+j)&1) f[i][j] = min(f[i][j-1]+a[i][j-1]*a[i][j],f[i-1][j]+a[i-1][j]*a[i][j]);
                else f[i][j] = min(f[i][j-1],f[i-1][j]);
            }
        printf("%d\n",f[n][m]);
    }

	return 0;
}
