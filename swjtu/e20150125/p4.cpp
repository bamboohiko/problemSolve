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
int tree[801000],h,w,k;
void build(int l,int r,int p)
{
	if (l == r)
	{
		tree[p] = w;
		return;
	}
	int mid = (l + r) >> 1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	tree[p] = w;
}
int query(int l,int r,int p,int x)
{
	if (tree[p] < x) return -1;
	if (l == r)
	{
		tree[p] -= x;
		return l;
	}
	int mid = (l + r) >> 1,r1 = 0,r2 = 0;
	r1 = query(l,mid,p*2,x);
	if (r1 == -1) r2 = query(mid+1,r,p*2+1,x);
	tree[p] = max(tree[p*2],tree[p*2+1]);
	if (r2 <= 0) return r1;
	else return r2; 
}
int main()
{
	while (scanf("%d%d%d",&h,&w,&k) != EOF)
	{
		h = min(h,k);
		build(1,h,1);
		for (int i = 1;i <= k; i++)
		{
			int x;
			scanf("%d",&x);
			printf("%d\n",query(1,h,1,x));
		}
	}
	return 0;
}

