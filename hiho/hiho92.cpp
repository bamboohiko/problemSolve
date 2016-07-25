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
const int prime[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
const int S = 12;
LL modpow(LL a,LL b,LL m) {
    LL t = 1;
    while (b) {
        if (b%2) t = t*a%m;
        t = t*t%m;
        b >>= 1;
    }
    return t;
}
bool Miller_Rabin(LL k) {
    if (k == 2) return true;
    if (k&1 == 0) return false;
    LL u = k-1;
    while (u&1 == 0) u >>= 1;
    for (int i = 0;i < S; i++) {
        LL a = prime[i];
        if (a >= k) break;
        //cout << a << " " << u  << " " << k << endl;
        LL x = modpow(a,u,k);
        for (LL i = u;i < k;i <<= 1) {
            LL y = x*x%k;
            if (y == 1 && x != 1 && x != k-1) return false;
            x = y;
        }
        if (x != 1) return false;
    }
    return true;
}
int main() {
    int t;LL n;
    scanf("%d",&t);
    while (t--) {
        scanf("%lld",&n);
        if (Miller_Rabin(n)) puts("Yes");
        else puts("No");
    }
	return 0;
}

