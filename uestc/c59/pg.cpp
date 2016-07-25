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
struct matrix {
	long long x,y;
	matrix operator =(const matrix &rhs) {
		matrix ans;
		ans.x = rhs.x;
		ans.y = rhs.y;
		return ans;
	}
};
matrix Q[200100];
int main()
{
	int n,len = 1;long long ans = 0;
	scanf("%d",&n);
	matrix loc;
	scanf("%lld%lld",&Q[1].x,&Q[1].y);
	ans = max(ans,Q[1].x*Q[1].y);
	for (int i = 2;i <= n; i++) {
		scanf("%lld%lld",&loc.x,&loc.y);
		while (len && loc.y < Q[len].y) loc.x += Q[len--].x;
		ans = max(ans,loc.x*loc.y);
		Q[++len].x = loc.x;Q[len].y = loc.y;
	}
	long long sumx = 0;
	for (int i = len;i >= 1; i--) {
		sumx += Q[i].x;
		ans = max(ans,sumx*Q[i].y);
	}
	printf("%lld\n",ans);
	return 0;
}
