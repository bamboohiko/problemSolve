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
const LL mod = 1000003;
const int maxn = 1e6;
LL mul[maxn + 10];
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
     if (d == 1) return (x%mod + mod)%mod;
     else return -1;
}
void init() {
    mul[0] = 1;
    for (int i = 1;i <= maxn; i++)
        mul[i] = mul[i-1]*i%mod;
}
int main() {
    init();
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        int n,k;
        scanf("%d%d",&n,&k);
        LL ans = mul[n]*inv(mul[k])%mod*inv(mul[n-k])%mod;
        printf("Case %d: %lld\n",ca,ans);
    }
	return 0;
}

