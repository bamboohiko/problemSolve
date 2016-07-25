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
int f[510][510];
int main() {
    int t,n,d;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        memset(f,0,sizeof(f));
        scanf("%d%d",&n,&d);
        for (int len = 1;len < n; len++)
            for (int i = 1;i + len <= n; i++) {
                int j = i + len;
                f[i][j] = inf;
                for (int k = i;k <= j; k++)
                    f[i][j] = min(f[i][j],f[i][k-1] + f[k+1][j] + (j-i+1)*(d+k));
                //printf("%d %d %d\n",i,j,f[i][j]);
            }
        printf("Case %d: %d\n",ca,f[1][n]);
    }
	return 0;
}
