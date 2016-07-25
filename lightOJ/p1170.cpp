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
const LL maxn = 1e10;
const LL maxm = 1e5 ;
const LL mod = 100000007;
LL mul[(maxm << 1) + 10],a[(maxm << 1) + 10],m = 0;
set<LL> S;
void init() {
    mul[0] = 1;
    for (int i = 1;i <= (maxm << 1); i++)
        mul[i] = mul[i-1]*i%mod;
    for (LL i = 2;i <= maxm; i++) {
        for (LL j = i*i;j <= maxn; j *= i) S.insert(j);
    }
    for (set<LL>::iterator i = S.begin();i != S.end(); i++) {
        a[m++] = (*i);
    }
}
LL fig(LL x) {
    LL ans = upper_bound(a,a+m,x) - a;
    //printf("%lld %lld\n",x,ans);
    return ans;
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
    int t;
    scanf("%d",&t);
    LL l,r;
    for (int ca = 1;ca <= t;ca++) {
        scanf("%lld %lld",&l,&r);
        LL n = fig(r) - fig(l-1),ans;
        //printf("%lld\n",n);
        if (n == 0) ans = 0;
        else if (n == 1) ans = 1;
        else ans = mul[n << 1]*inv(mul[n])%mod*inv(mul[n])%mod*inv(n+1)%mod;
        printf("Case %d: %lld\n",ca, ans);
    }
	return 0;
}

