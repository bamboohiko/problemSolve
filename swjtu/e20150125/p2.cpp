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
const int INF = 1 << 28;
int tree[801000];
void push(int p)
{
	tree[p] = max(tree[p*2],tree[p*2+1]);
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
void updata(int l,int r,int p,int pos,int x)
{
	if (l == r)
	{
		tree[p] = x;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) updata(l,mid,p*2,pos,x);
	if (pos > mid) updata(mid+1,r,p*2+1,pos,x);
	push(p);
}
int query(int l,int r,int p,int x,int y)
{
	if (x <= l && r <= y)
		return tree[p];
	int mid = (l + r) >> 1,ans = -INF;
	if (x <= mid) ans = max(ans,query(l,mid,p*2,x,y));
	if (y > mid) ans = max(ans,query(mid+1,r,p*2+1,x,y));
	return ans;
}
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF)
	{
		build(1,n,1);
		for (int i = 1;i <= m; i++)
		{
			char ch;int x,y;
			scanf("%*c%c %d %d",&ch,&x,&y);
			if (ch == 'U') updata(1,n,1,x,y);
			if (ch == 'Q') printf("%d\n",query(1,n,1,x,y));
		}
	}
	return 0;
}

