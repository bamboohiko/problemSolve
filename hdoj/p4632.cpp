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
const int mod = 10007;
char st[1010];
int f[1010][1010],n;
int main() {
    int t;
    scanf("%d%*c",&t);
    for (int ca = 1;ca <= t; ca++) {
        memset(f,0,sizeof(f));
        gets(st+1);st[0] = ' ';
        n = strlen(st) - 1;
        for (int i = 1;i <= n; i++) f[i][i] = 1;
        for (int len = 1;len < n; len++)
            for (int l = 1;l + len <= n; l++) {
                int r = l + len;
                if (st[l] == st[r]) f[l][r] = (f[l+1][r] + f[l][r-1] + 1)%mod;
                else f[l][r] = (f[l+1][r] + f[l][r-1] - f[l+1][r-1] + mod)%mod;
            }
        printf("Case %d: %d\n",ca,f[1][n]);
    }
	return 0;
}

