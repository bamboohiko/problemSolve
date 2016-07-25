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
const LL mod = 1e9 + 7;
const int maxn = 1e5 + 10;
map<int,int> dir;
struct inter {
    int l,r;
};
inter a[maxn];
int rec[2*maxn];
LL e2[maxn],loc[2*maxn];
void init() {
    e2[0] = 1;
    for (int i = 1;i < maxn; i++)
        e2[i] = e2[i-1]*2%mod;
}
int main() {
    init();
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        memset(rec,0,sizeof(rec));
        dir.clear();
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) {
            scanf("%d%d",&a[i].l,&a[i].r);
            dir[a[i].l] = 1;dir[a[i].r] = 1;
        }
        map<int,int>::iterator op = dir.begin(), ed = dir.end();
        int m = dir.size();
        for (int i = 1;op != ed;op++,i++) {
            op->second = i;
            loc[i] = op->first;
        }
        for (int i = 1;i <= n; i++) {
            rec[dir[a[i].l]]++;rec[dir[a[i].r]]--;
        }
        LL cou = rec[1], ans = 0;
        for (int i = 2;i <= m; i++) {
            //cout << cou << endl;
            ans = (ans + (loc[i] - loc[i-1])*(e2[n] + mod - e2[n - cou])%mod)%mod;
            cou += rec[i];
        }
        printf("%lld\n",ans);
    }
	return 0;
}

