#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
const LL mod = 1000000007;
const int n = 1e6;
LL fac[n + 10],p2[n + 10];
void init() {
    fac[0] = p2[0]  = 1;
    for (int i = 1;i <= n; i++) {
        fac[i] = fac[i-1]*i%mod;
        p2[i] = p2[i-1]*2%mod;
    }
}
int main()
{
    init();
    int t,k,turn = 0;
    scanf("%d",&t);
    while (turn++ < t) {
        scanf("%d",&k);
        printf("Case #%d:\n%I64d\n",turn,1 + fac[k]/fac[k/2]/p2[k/2]*(p2[k/2] - 1)%mod);
    }
	return 0;
}
