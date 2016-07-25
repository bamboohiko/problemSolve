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
LL tree[500100],lazy[500100];
void push(int k)
{
	tree[k] = tree[k+k] + tree[k+k+1];
}
void down(int k,int l,int r)
{
	int mid = (l+r) >> 1;
	if (lazy[k])
	{
		lazy[k+k] += lazy[k];
		tree[k+k] += (mid-l+1)*lazy[k];
		//cout << lazy[k+k] << " " << lazy[k] << endl;
		lazy[k+k+1] += lazy[k];
		tree[k+k+1] += (r-mid)*lazy[k]; 
		lazy[k] = 0;
	}
}
void build(int l,int r,int k)
{
	if (l == r) 
	{
		scanf("%lld",&tree[k]);
		return;
	}
	int mid = (l + r) >> 1;
	build(l,mid,k+k);
	build(mid+1,r,k+k+1);
	push(k);
}
LL updata(int l,int r,int k,int x,int y,int d)
{
	if (x <= l && r <= y)
	{
		lazy[k] += d;
		return tree[k] += (r-l+1)*d;
	}
	int mid = (l + r) >> 1;
	down(k,l,r);
	if (x <= mid) updata(l,mid,k+k,x,y,d);
	if (y > mid) updata(mid+1,r,k+k+1,x,y,d);
	push(k);
}
LL sum(int l,int r,int k,int x,int y)
{
	if (x <= l && r <= y)
		return tree[k];
	down(k,l,r);
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
	//for (int i = 1;i <= n+n; i++) cout << tree[i] << " ";cout << endl;
	scanf("%d",&m);
	for (int i = 1;i <= m; i++)
	{
		int t,l,r,d;
			scanf("%d%d%d",&l,&r,&d);
			updata(1,n,1,l,r,d);
			printf("%lld\n",sum(1,n,1,l,r));
	}
	return 0;
}
