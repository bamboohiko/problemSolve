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
bool vis[2010];
int prime[2010],m = 0;
int a[310][310];
void init() {
    int maxn = 2000;
    for (int i = 2;i <= maxn; i++)
        if (!vis[i]) {
            prime[m++] = i;
            for (int j = i+i;j <= maxn; j += i) vis[j] = true;
        }
}
LL modpow(LL a,LL b) {
    LL ans = 1;
    while (b) {
        if (b&1) ans = ans*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ans;
}
int main() {
    init();
    int t,n;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++){
        scanf("%d",&n);
        LL k;
        memset(a,0,sizeof(a));
        for (int i = 0;i < n; i++) {
            scanf("%I64d",&k);
            for (int j = 0;j < m; j++)
                while (k%prime[j] == 0) {
                    k /= prime[j];
                    a[j][i] ^= 1;
                }
        }
        int ret = 0;
        for (int i = 0, it = 0; i < m && it < n; it++) {
            int pos = -1;
            for (int j = i; j < m; j++) {
                if (a[j][it]) {
                    pos = j;
                    break;
                }
            }
            if (pos == -1)  continue;
            ++ret;
            if (pos != i) {
                for (int j = 0; j < n; ++j)
                    swap(a[i][j], a[pos][j]);
            }
            for (int j = 0; j < m; j++) {
                if (i != j && a[j][it]) {
                    for (int k = it; k < n; k++) {
                        a[j][k] ^= a[i][k];
                    }
                }
            }
            i++;
        }
        int ans = (modpow(2,n-ret) + mod-1)%mod;
        printf("Case #%d:\n%d\n",ca,ans);
    }
	return 0;
}
