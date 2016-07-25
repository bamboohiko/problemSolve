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
const LL mod = 20072288;
const int maxn = 1000;
LL f[1010];
int main() {
    f[0] = 1;
    for (int k = 1;k <= maxn; k++) {
        int l = min(maxn,k*(k+1)/2);
        for (int n = l;n >= k; n--)
            f[n] = (f[n] + f[n-k])%mod;
    }
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        printf("%d\n",f[n]);
    }
	return 0;
}
