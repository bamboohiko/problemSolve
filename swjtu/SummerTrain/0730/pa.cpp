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
const LL mod = 29;
LL modexp(LL a,LL b) {
    LL t = 1;
    while (b) {
        if (b%2 == 1) t = t*a%mod;
        a = a*a%mod;
        b /= 2;
    }
    return t;
}
LL exgcd(LL a,LL b,LL& x,LL& y) {
    if (a == 0 && b == 0) return -1;
    if (b == 0) {x = 1;y = 0;return a;}
    LL d = exgcd(b,a%b,y,x);
    y -= a/b*x;
    return d;
}
LL inv(LL a,LL n) {
    LL x,y;
    LL d = exgcd(a,n,x,y);
    if (d == 1) return (x%n+n)%n;
    else return -1;
}
int main() {
    LL x;
    while (scanf("%lld",&x) != EOF && x) {
        LL ans = (modexp(2,2*x+1)-1)*(modexp(3,x+1)-1)%mod*inv(2,mod)%mod*(modexp(167,x+1)-1)%mod*inv(166,mod)%mod;
        printf("%d\n",ans);
    }
	return 0;
}

