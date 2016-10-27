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
LL k[310],v[310],f[310][310][2];
bool a[310][310];
bool gcd(LL a,LL b) {
    while (b) {
        LL t = a;a = b;b = t%b;
    }
    return (a > 1);
}
int main() {
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) scanf("%I64d",&k[i]);
        for (int i = 1;i <= n; i++) scanf("%I64d",&v[i]);
        for (int i = 1;i <= n; i++)
            for (int j = i+1;j <= n; j++)
                a[i][j] = gcd(k[i],k[j]);
        memset(f,0,sizeof(f));
        for (int len = 1;len < n;len++)
            for (int i = 1;i+len <= n; i++) {
                int j = i+len;
                if (a[i][j] && (f[i+1][j-1][1] > 0 || i+1 > j-1)) f[i][j][1] = f[i+1][j-1][1] + v[i] + v[j];
                for (int k = i;k < j; k++) {
                    if (f[i][k][1] > 0 && f[k+1][j][1] > 0) f[i][j][1] = max(f[i][j][1],f[i][k][1]+f[k+1][j][1]);
                    f[i][j][0] = max(f[i][j][0],f[i][k][0]+f[k+1][j][0]);
                }
                f[i][j][0] = max(f[i][j][1],f[i][j][0]);
            }
        printf("%I64d\n",f[1][n][0]);
    }
	return 0;
}
