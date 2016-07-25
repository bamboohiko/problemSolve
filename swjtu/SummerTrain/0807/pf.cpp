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
LL a[1010],sum[1010];
int main() {
    int n,q;
    while (scanf("%d",&n) != EOF && n) {
        for (int i = 1;i <= n; i++) {
            scanf("%lld",&a[i]);
            sum[i] = sum[i-1] + a[i];
        }
        scanf("%d",&q);
        int l,r,p;
        for (int i = 1;i <= q; i++) {
            scanf("%d%d",&l,&r);
            p = (l + r) >> 1;
            LL ans = a[p]*(p+p-l-r) - (sum[p-1]-sum[l-1]) + (sum[r] - sum[p]);
            printf("%lld\n",ans);
        }
    }
	return 0;
}

