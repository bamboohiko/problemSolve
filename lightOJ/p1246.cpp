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
LL p[100];
void init() {
    p[0] = 1;
    for (int i = 1;i <= 50; i++)
        p[i] = p[i-1]*i%mod;
}
LL exgcd(LL a,LL b,LL &x,LL &y) {
    if (b == 0) {x = 1;y = 0;return a;}
    LL d = exgcd(b,a%b,y,x);
    y -= a/b*x;
    return d;
}
LL inv(LL a) {
    LL x,y;
    LL d = exgcd(a,mod,x,y);
    return (x%mod + mod)%mod;
}
int main() {
    init();
    int t,n,m,k;
    scanf("%d",&t);
    for (int ca = 1;ca <= t;ca++) {
        scanf("%d%d%d",&n,&m,&k);
        int a,b;
        a = ((n+1)*(m+1)) >> 1,b = (n+1)*(m+1) - a;
        LL ans = 0;
        for (int i = 1;i < k; i++) {
            LL mul = p[k]*inv(p[i])%mod*inv(p[k-i])%mod;
            //printf("%lld %lld %lld\n",p[k],inv(p[i]),inv(p[k-i]));
            for (int j = 1;j <= a; j++) mul = mul*(LL)i%mod;
            for (int j = 1;j <= b; j++) mul = mul*(LL)(k-i)%mod;
            ans = (ans + mul)%mod;
            cout << ans << endl;
        }
        if (k == 1 && n == 0 && m == 0) ans = 1;
        printf("Case %d: %lld\n",ca,ans);
    }
	return 0;
}

