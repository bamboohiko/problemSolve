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
int r[100100],c[100100],g[];
int lowbit(int k) {
	return k & (-k);
}
void updata(int a[],int k,int n) {
	while (k <= n) {
		a[k] += 1;
		k += lowbit(k);
	}
}
void updata2d()
int getsum(int a[],int k) {
	int ans = 0;
	while (k > 0) {
		ans += a[k];
		k -= lowbit(k);
	}
	return ans;
}
int main()
{
	int n,m,k,q;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for (int i = 1;i <= k; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		updata(r,x,n);
		updata(c,y,m);
		updata2d()
	}
	for (int i = 1;i <= q; i++) {
		int xl,xr,yl,yr;
		scanf("%d%d%d%d",&xl,&yl,&xr,&yr);
		printf("%d %d %d %d\n",getsum(r,xr),getsum(r,xl-1),getsum(c,yr),getsum(c,yl-1));
		if (getsum(r,xr) - getsum(r,xl-1) == xr-xl+1 
			&& getsum(c,yr) - getsum(c,yl-1) == yr-yl+1)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
