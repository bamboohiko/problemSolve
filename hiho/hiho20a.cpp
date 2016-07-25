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
int tree[400100],lazy[400100];
void push(int p)
{
	tree[p] = tree[p*2] + tree[p*2+1];
}
void down(int l,int r,int p)
{
	if (lazy[p])
	{
		int mid = (l + r) >> 1;
		lazy[p*2] = lazy[p*2+1] = lazy[p];
		tree[p*2] = lazy[p]*(mid-l+1);
		tree[p*2+1] = lazy[p]*(r-mid);
		lazy[p] = 0;
	}
}
void build(int l,int r,int p)
{
	if (l == r)
	{
		scanf("%d",&tree[p]);
		return;
	}
	int mid = (l + r) >> 1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	push(p);
}
void updata(int l,int r,int p,int x,int y,int num)
{
	if (x <= l && r <= y)
	{
		lazy[p] = num;
		tree[p] = num*(r-l+1);
		return;
	}
	down(l,r,p);
	int mid = (l + r) >> 1;
	if (x <= mid) updata(l,mid,p*2,x,y,num);
	if (y > mid) updata(mid+1,r,p*2+1,x,y,num);
	push(p);
}
int quary(int l,int r,int p,int x,int y)
{
	if (x <= l && r <= y)
		return tree[p];
	down(l,r,p);
	int mid = (l + r) >> 1,ans = 0;
	if (x <= mid) ans += quary(l,mid,p*2,x,y);
	if (y > mid) ans += quary(mid+1,r,p*2+1,x,y);
	return ans;
}
int main()
{
	int n,q;
	scanf("%d",&n);
	build(1,n,1);
	scanf("%d",&q);
	for (int i = 1;i <= q; i++)
	{
		int t,x,y,num;
		scanf("%d%d%d",&t,&x,&y);
		if (t == 1) 
		{
			scanf("%d",&num);
			updata(1,n,1,x,y,num);
		}
		if (t == 0)
			printf("%d\n",quary(1,n,1,x,y));
	}
	return 0;
}

