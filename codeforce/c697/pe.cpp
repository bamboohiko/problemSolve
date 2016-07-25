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
const LL mod = 1e9 + 7;
const LL mul = 333333336;
LL exgcd(LL& x,LL& y,LL a,LL b) {
    if (b == 0) {
        x = 1;y = 0;
        return a;
    } else {
        LL t = exgcd(y,x,b,a%b);
        y -= a/b*x;
        return t;
    }
}
LL modexp(LL a,LL b,LL n) {
    LL ans = 1;
    while (b) {
        if (b&1) ans = ans*a%n;
        a = a*a%n;
        b >>= 1;
    }
    return ans;
}
int main() {
    //LL x,y;
    //exgcd(x,y,3,mod);
    //cout << x << " " << y << endl;
    int n;
    scanf("%d",&n);
    LL k,m = 1,sgn = -1;
    for (int i = 1;i <= n; i++) {
        scanf("%I64d",&k);
        m = (m*(k%(mod-1)))%(mod-1);
        if ((k&1) == 0) sgn = 1;
    }
    m = (m+mod-2)%(mod-1);
    LL q = modexp(2,m,mod);
    LL p = (q+sgn+mod)%mod*mul%mod;
    printf("%I64d/%I64d\n",p,q);
	return 0;
}
