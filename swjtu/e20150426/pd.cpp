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
const int m = 1000;
LL a[1010];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--) {
		memset(a,0,sizeof(a));
		int n,q,c;
		scanf("%d",&n);
		for (int i = 0;i < n; i++) {
			int k;
			scanf("%d",&k);
			a[k]++;
		}
		scanf("%d",&q);
		for (int i = 1;i <= q; i++) {
			LL ans = 0;
			scanf("%d",&c);
			for (int i = 0;i <= m; i++) {
				if (c < i || c-i > m) continue;
				if (c == i+i) ans += a[i]*(a[i]-1);
				else ans += a[i]*a[c-i];
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
