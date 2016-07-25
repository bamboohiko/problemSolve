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
const LL mod = 1000007;
const int maxn = 400;
const LL sg[16] = {1,-1,-1,-1,-1,1,1,1,1,1,1,-1,-1,-1,-1,1};
const LL d[16][2] = {0,0,-1,0,-1,0,0,-1,0,-1,-2,0,0,-2,-1,-1,-1,-1,-1,-1,-1,-1,-2,-1,-2,-1,-1,-2,-1,-2,-2,-2};
LL mul[maxn + 10],c[maxn + 10][maxn + 10];
void init() {
    mul[0] = 1;
    for (int i = 1;i <= maxn; i++) {
        mul[i] = mul[i-1]*i%mod;
    }
    for (int i = 0;i <= maxn; i++) {
        c[i][0] = 1;
        for (int j = 1;j <= i; j++)
            c[i][j] = (c[i-1][j] + c[i-1][j-1])%mod;

    }
}
LL fig(int n,int k) {
    //if (n >= k) cout << c[n][k] << endl;
    if (n < k) return 0;
    else return c[n][k];
}
int main() {
    init();
    int t,n,m,k;
    scanf("%d",&t);
    for (int ca = 1;ca <= t;ca++) {
        scanf("%d%d%d",&n,&m,&k);
        LL ans = 0;
        for (int i = 0;i < 16; i++)
            ans = (ans + sg[i]*fig((n+d[i][0])*(m+d[i][1]),k))%mod;
        printf("Case %d: %lld\n",ca, (ans + mod)%mod);
    }
	return 0;
}

