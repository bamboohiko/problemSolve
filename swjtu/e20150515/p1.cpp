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
long long pri(long long k) {
	return (k/5) - (k/403) - (k/65) - (k/155) + (k/13) + (k/31)  + (k/2015);
}
int main()
{
	int t;long long l,r;
	scanf("%d",&t);
	for (int ca = 1;ca <= t; ca++) {
		scanf("%lld%lld",&l,&r);
		long long ans = pri(r) - pri(l-1);
		if (2015 >= l && 2015 <= r) ans--; 
		printf("Case #%d: %lld\n",ca,ans);
	}
	return 0;
}
