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
int a[200100];
int main()
{
	int n,k;
	while (scanf("%d%d",&n,&k) != EOF) {
		for (int i = 0;i < n; i++) 
			scanf("%d",&a[i]);
		sort(a,a+n);
		LL ans = 0;
		for (int i = 0;i < n; i++) {
			if (a[i] > k/2) {
				int mid = n-(i+1);
				ans += (mid+1)*mid/2;
				break;
			}
			int loc = lower_bound(a+i,a+n,k-a[i]) - a;
			//cout << loc << endl;
			if (loc <= i) loc++;
			ans += n - loc;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
