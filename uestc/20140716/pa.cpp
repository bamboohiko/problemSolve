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
LL f[110][110],a[110];
int main() {
    int t;
    scanf("%d",&t);
    for (int T = 1;T <= t; T++) {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n; i++) scanf("%I64d",&a[i]);
        sort(a+1,a+n+1);
        memset(f,INF,sizeof(f));
        f[0][0] = 0;
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= i; j++) {
                f[i][j] = f[i-1][j-1];
                for (int k = j-1;k < i; k++)
                    f[i][j] = min(f[i][j],f[k][j-1]+a[i]-a[k+1]);
            }
        printf("Case #%d: %lld\n",T,f[n][m]);
    }
	return 0;
}
