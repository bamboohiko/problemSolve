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
const int maxn = 1e6;
const LL mod = 1000000007;
LL mul[maxn + 10];
void init() {
    mul[0] = 1;
    for (int i = 1;i <= maxn; i++)
        mul[i] = mul[i-1]*i%mod;
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
    int t,n;
    scanf("%d",&t);
    for (int ca = 1;ca <= t;ca++) {
        scanf("%d",&n);
        int sum = 0,k;
        LL ans = 1;
        scanf("%d",&sum);
        for (int i = 2;i <= n; i++) {
            scanf("%d",&k);
            ans = ans*mul[sum+k-1]%mod*inv(mul[sum])%mod*inv(mul[k-1])%mod;
            sum += k;
        }
        printf("Case %d: %lld\n",ca, ans);
    }
	return 0;
}

