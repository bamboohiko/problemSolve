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
const int maxn = 1e5 + 10;
const LL mod = 1e9 + 7;
map<int ,int> dir;
LL cou[maxn],e2[maxn];
void init() {
    e2[0] = 1;
    for (int i = 1;i < maxn; i++)
        e2[i] = (e2[i-1] << 1)%mod;
}
int main() {
    init();
    int t;
    scanf("%d",&t);
    while (t--) {
        dir.clear();
        memset(cou,0,sizeof(cou));
        int n;
        scanf("%d",&n);
        LL ans = 0,k;
        for (int i = 1;i <= n; i++) {
            scanf("%lld",&k);
            if (!dir.count(k)) dir[k] = dir.size();
            ans = (ans +((e2[i-1] + mod - cou[dir[k]])%mod*e2[n-i]%mod*k%mod)mod;
            cou[dir[k]] = (cou[dir[k]] + e2[i-1])%mod;
            //cout << ans << " ";
        }
        printf("%lld\n",ans);
    }
	return 0;
}

