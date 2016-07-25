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
LL tree[1000100];
LL push(int k)
{
	tree[k] = tree[k+k] + tree[k+k+1];
	//tree[k] = min(tree[k+k],tree[k+k+1]);
}
void build(int l,int r,int k)
{
	if (l == r) {
		scanf("%d",&tree[k]);
		return;
	}
	int mid = (l+r) >> 1;
	build(l,mid,k+k);
	build(mid+1,r,k+k+1);
	push(k);
}
void updata(int l,int r,int k,int x,int v)
{
	if (l == r)
	{
		tree[k] = v;
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) updata(l,mid,k+k,x,v);
	if (x > mid) updata(mid+1,r,k+k+1,x,v);
	push(k);
}
LL sum(int l,int r,int k,int x,int y)
{
	if (x <= l && r <= y)
	{
		return tree[k];
	}
	int mid = (l+r) >> 1;LL ans = 0;
	if (x <= mid) ans += sum(l,mid,k+k,x,y);
	if (y > mid) ans += sum(mid+1,r,k+k+1,x,y);
	return ans;
}
int main()
{
	int n,m;
	scanf("%d",&n);
	build(1,n,1);
	scanf("%d",&m); 
	for (int i = 1;i <= m; i++) {
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		if (t == 1) updata(1,n,1,l,r);
		else printf("%lld\n",sum(1,n,1,l,r));
	}
	return 0;
}

