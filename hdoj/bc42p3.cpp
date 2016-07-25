#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[110][110],f[110][110][110];
int main()
{
    int n,m,t;
    while (scanf("%d%d%d",&n,&m,&t) != EOF) {
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= m; j++)
                scanf("%d",&a[i][j]);
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= m; j++)
                for (int k = 0;k <= t; k++) {
                    f[i][j][k] = max(f[i-1][j][k],f[i][j-1][k]);
                    if (k >= a[i][j]) f[i][j][k] = max(f[i][j][k],max(f[i-1][j][k-a[i][j]],f[i][j-1][k-a[i][j]])+a[i][j]);
                }
        printf("%d\n",f[n][m][t]);
    }
	return 0;
}
