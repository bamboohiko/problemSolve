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
LL modexp(LL a,LL b,LL n) {
    LL ans = 1;
    while (b) {
        if (b&1) ans = ans*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ans;
}
int main() {
    LL n,m;
    while (cin >> n >> m) {
        LL ans = 0;
        for (int i = n+m-1; i <= n*m; i++) {
            ans = c(n*m,)
        }
    }
	return 0;
}
