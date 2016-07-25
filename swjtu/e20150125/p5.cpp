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
int tree[801000],a[201000],pos[201000],val[201000];
void push(int p)
{
	tree[p] = tree[p*2] + tree[p*2+1];
}
void build(int l,int r,int p)
{
	if (l == r) 
	{
		tree[p] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	push(p);
}
void updata(int l,int r,int p,int pos,int x)
{
	if (l == r)
	{
		a[l] = x;
		tree[p] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	if (tree[p*2] > pos) updata(l,mid,p*2,pos,x);
	else updata(mid+1,r,p*2+1,pos-tree[p*2],x);
	push(p);
}
int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		build(1,n,1);
		for (int i = 1;i <= n; i++)
			scanf("%d%d",&pos[i],&val[i]);
		for (int i = n;i >= 1; i--)
			updata(1,n,1,pos[i],val[i]);
		for (int i = 1;i < n; i++) 
			printf("%d ",a[i]);
		printf("%d\n",a[n]);
	}
	return 0;
}

