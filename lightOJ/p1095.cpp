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
typedef long long LL;
const LL mod = 1000000007;
LL mul[1010];
void init() {
    mul[0] = 1;
    for (int i = 1;i <= 1000; i++)
        mul[i] = mul[i-1]*i%mod;
}
LL exgcd(LL a,LL b,LL &x,LL &y) {
    if (a == 0 && b == 0) return -1;
    if (b == 0) {x = 1;y = 0;return a;}
    LL d = exgcd(b,a%b,y,x);
    y -= a/b*x;
    return d;
}
LL inv(LL a) {
    LL x,y;
    LL d = exgcd(a,mod,x,y);
    if (d == 1) return (x%mod+mod)%mod;
    else return -1;
}
int main() {
    init();
    int t;
    scanf("%d",&t);
    int n,m,k;
    for (int ca = 1;ca <= t;ca++) {
        scanf("%d%d%d",&n,&m,&k);
        LL sum = 0,sg = 1;
        for (int i = 1;i <= m-k; i++) {
            sum = (sum + sg*mul[m-k]*inv(mul[i])%mod*inv(mul[m-k-i])%mod*mul[n-k-i]%mod + mod)%mod;
            sg *= -1;
        }
        LL ans = (mul[n-k] + mod -sum)%mod*mul[m]%mod*inv(mul[k])%mod*inv(mul[m-k])%mod;
        printf("Case %d: %lld\n",ca,ans);
    }
	return 0;
}

