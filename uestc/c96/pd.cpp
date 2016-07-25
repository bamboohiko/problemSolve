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
const LL mod = 1000000007;
char st[310];
LL f[310][310];
int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",st+1);
    for (int i = 1;i <= n+1; i++) f[i][i] = f[i][i-1] = 1;
    for (int len = 1;len < n; len++)
        for (int l = 1;l + len <= n; l++) {
            int r = l + len;
            f[l][r] = f[l+1][r];
            for (int k = l+1;k <= r; k++)
                if ((st[l] == '(' && st[k] == ')') || (st[l] == '[' && st[k] == ']'))
                    f[l][r] = (f[l][r] + f[l+1][k-1]*f[k+1][r]%mod)%mod;
        }
    printf("%lld\n",(f[1][n]+mod-1)%mod);
	return 0;
}
