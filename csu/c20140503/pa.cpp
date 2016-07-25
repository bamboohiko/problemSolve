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
int a[30];
int main()
{
	int t,n;
	scanf("%d",&t);
	while (t--) {
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for (int i = 1;i <= n; i++) {
			int l,r;
			scanf("%d%d",&l,&r);
			for (int j = l;j <= r; j++) a[j]++;
		}
		int ans = 0;
		for (int i = 0;i <= 25; i++)
			ans = max(ans,a[i]);
		printf("%d\n",ans);
	}
	return 0;
}
