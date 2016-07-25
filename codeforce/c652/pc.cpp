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
const int maxn = 3e5 + 100;
struct point {
    LL l,r;
    bool operator <(const point &rhs) const {
        return r < rhs.r;
    }
};
int loc[maxn];
point a[maxn];
int main() {
    int n,m,k;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&k);
        loc[k] = i;
    }
    int from,to;
    for (int i = 1;i <= m; i++) {
        scanf("%d%d",&from,&to);
        a[i].l = min(loc[from],loc[to]);
        a[i].r = max(loc[from],loc[to]);
    }
    sort(a+1,a+m+1);
    LL ans = 0,l = 0,r = 1;
    for (int i = 1;i <= m; i++) {
        ans += (a[i].r-r)*(r-l+a[i].r-l-1)/2;
        //cout << ans << endl;
        l = max(l,a[i].l);
        r = a[i].r;
    }
    ans += (n+1-r)*(r-l+n-l)/2;
    printf("%I64d\n",ans);
	return 0;
}

