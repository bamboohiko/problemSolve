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
int a[110],f[110][110];
int main() {
    int t,n;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        memset(f,0,sizeof(f));
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        for (int len = 0;len < n; len++)
            for (int i = 1;i + len <= n; i++) {
                int j = i + len,loc;
                f[i][j] = f[i+1][j] + 1;
                for (int k = i+1;k <= j; k++)
                    if (a[i] == a[k]){
                        f[i][j] = min(f[i][j],f[i+1][k-1]+f[k][j]);
                    }
            }
        printf("Case %d: %d\n",ca,f[1][n]);
    }
	return 0;
}

