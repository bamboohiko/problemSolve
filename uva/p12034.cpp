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
const int maxn = 1000;
const int mod = 10056;
int c[maxn + 10][maxn + 10],f[maxn + 10];
void init() {
    for (int i = 0;i <= maxn; i++) {
        c[i][0] = 1;
        for (int j = 1;j <= i; j++) {
            c[i][j] = (c[i-1][j-1] + c[i-1][j])%mod;
        }
    }
    f[0] = 1;
    for (int i = 1;i <= maxn; i++) {
        for (int j = 1;j <= i; j++)
            f[i] = (f[i] + f[i-j]*c[i][j]%mod)%mod;
    }
}
int main() {
    init();
    int t;
    scanf("%d",&t);
    for (int T = 1;T <= t; T++) {
        int n;
        scanf("%d",&n);
        printf("Case %d: %d\n",T,f[n]);
    }
	return 0;
}
