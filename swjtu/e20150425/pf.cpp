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
LL a[1010],b[1010];
bool cmp(LL a,LL b) {
	return a > b;
}
int main()
{
	int n,ca = 0;
	while (scanf("%d",&n) != EOF) {
		LL ans = 0;
		for (int i = 0;i < n; i++) scanf("%lld",&a[i]);
		sort(a,a+n);
		for (int i = 0;i < n; i++) scanf("%lld",&b[i]);
		sort(b,b+n,cmp);
		for (int i = 0;i < n; i++)
			ans += a[i]*b[i];
		printf("Case #%d:\n%lld\n",++ca,ans); 
	}
	return 0;
}
