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
const int maxn = 1000 + 10;
const int mod = 1e9 + 7;
typedef long long LL;
LL a[maxn],f[maxn][maxn];
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(f,0,sizeof(f));
        int n,p;
        scanf("%d%d",&n,&p);
        for (int i = 1;i <= n; i++) {
            scanf("%lld",&a[i]);
            a[i] = (a[i]%p+p)%p;
        }
        f[0][0] = 1;
        for (int i = 1;i <= n; i++)
            for (int j = p-1;j >= 0; j--)
                f[i][j] = (f[i-1][j] + f[i-1][((j-a[i])%p+p)%p])%mod;
        printf("%d\n",f[n][0]);
    }
	return 0;
}

