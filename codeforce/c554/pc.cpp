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
const LL maxn = 1e6 + 1010;
const LL mod = 1000000007;
LL mul[maxn + 100];
LL exgcd(LL a,LL b,LL &x,LL &y) {
    if (a == 0 && b == 0) return -1;
    if (b == 0) {x = 1,y = 0;return a;}
    LL d = exgcd(b,a%b,y,x);
    y -= a/b*x;
    return d;
}
/*
LL inv(LL a,LL m) {
    if (a == 1) return 1;
    return inv(m%a,m) * (m - m/a)%m;
}
*/
LL inv(LL a,LL n) {
    LL x,y;
    LL d = exgcd(a,n,x,y);
    if (d == 1) return (x%n + n)%n;
    else return -1;
}
LL c(int m,int n) {
    return mul[n]*inv(mul[m],mod)%mod*inv(mul[n-m],mod)%mod;
}
int main()
{
    int n;
    LL ans = 1, sum = 0, k;
    mul[0] = 1;
    for (int i = 1; i <= maxn; i++)
        mul[i] = mul[i-1] * i % mod;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        scanf("%I64d",&k);
        ans = ans * c(sum,sum+k-1) % mod;
        sum += k;
    }
    printf("%I64d\n",ans);
	return 0;
}
