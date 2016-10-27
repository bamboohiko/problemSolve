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
const int MAXN = 100;
const int MAXM = 100010;
const int MAXP = 666666;
const int MAX = 1000010;
#define setbit(ar, i) (((ar[(i) >> 6]) |= (1 << (((i) >> 1) & 31))))
#define chkbit(ar, i) (((ar[(i) >> 6]) & (1 << (((i) >> 1) & 31))))
#define isprime(x) (( (x) && ((x)&1) && (!chkbit(ar, (x)))) || ((x) == 2))
int dp[MAXN][MAXM];
int ar[(MAX >> 6) + 5] = {0};
int len = 0, prime[MAXP], cnt[MAX];
void Sieve() {
    setbit(ar, 0), setbit(ar, 1);
    for (int i = 3; (i * i) < MAX; i++, i++) {
        if (!chkbit(ar, i)) {
            int k = i << 1;
            for (int j = (i * i); j < MAX; j += k) setbit(ar, j);
        }
    }
    for (int i = 1; i < MAX; i++) {
        cnt[i] = cnt[i-1];
        if (isprime(i)) prime[len++] = i, cnt[i]++;
    }
}
void init() {
    Sieve();
    for (int n = 0; n < MAXN; n++) {
        for (int m = 0; m < MAXM; m++) {
            if (!n) dp[n][m] = m;
            else dp[n][m] = dp[n-1][m] - dp[n-1][m/prime[n - 1]];
        }
    }
}
LL phi(LL m, int n) {
    if (n == 0) return m;
    if (prime[n - 1] >= m) return 1;
    if (m < MAXM && n < MAXN) return dp[n][m];
    return phi(m,n-1) - phi(m/prime[n-1],n-1);
}
LL Lehmer(LL m) {
    if (m < MAX) return cnt[m];
    LL res = 0;
    int a,s,y;
    s = sqrt(0.9 + m), y = cbrt(0.9 + m);
    a = cnt[y], res = phi(m,a) + a-1;
    for (int i = a; prime[i] <= s; i++) res = res - Lehmer(m/prime[i]) + Lehmer(prime[i])-1;
    return res;
}
int main() {
    init();
    LL n;
    while (scanf("%I64d", &n) != EOF) {
        printf("%I64d\n", Lehmer(n));
    }
    return 0;
}
