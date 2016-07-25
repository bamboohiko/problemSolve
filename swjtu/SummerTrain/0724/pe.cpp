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
const int maxn = 200;
LL mul[maxn + 10];
LL inv(LL a,LL m) {
    if (a == 1) return 1;
    return inv(m%a,m)*(m-m/a)%m;
}
int main() {
    mul[0] = 1;
    for (int i = 1;i <= maxn; i++) mul[i] = mul[i-1]*i%mod;
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        int n,r;
        scanf("%d%d",&n,&r);
        LL ans = mul[r+n-1]*inv(mul[r],mod)%mod*inv(mul[n-1],mod)%mod;
        printf("Case #%d: %lld\n",ca,ans);
    }
	return 0;
}
