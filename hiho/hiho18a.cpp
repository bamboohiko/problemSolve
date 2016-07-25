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
int tree[4000100];
void push(int p)
{
	tree[p] = min(tree[p*2],tree[p*2+1]);
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
	//cout << l << " "<< r << " " << tree[p] << endl; 
}
void updata(int l,int r,int p,int pos,int x)
{
	if (l == r)
	{
		tree[p] = x;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <=  mid) updata(l,mid,p*2,pos,x);
	else updata(mid+1,r,p*2+1,pos,x);
	push(p);
}
int quary(int l,int r,int p,int x,int y)
{
	if (x <= l && r <= y)
		return tree[p];
	int mid = (l + r) >> 1,ans = INF;
	if (x <= mid) ans = min(ans,quary(l,mid,p*2,x,y));
	if (y > mid) ans = min(ans,quary(mid+1,r,p*2+1,x,y));
	return ans;
}
int main()
{
	int n,q;
	while (scanf("%d",&n) != EOF)
	{
		build(1,n,1);
		scanf("%d",&q);
		for (int i = 1;i <= q; i++)
		{
			int t,x,y;
			scanf("%d%d%d",&t,&x,&y);
			if (t == 1) updata(1,n,1,x,y);
			if (t == 0) printf("%d\n",quary(1,n,1,x,y));
		}
	}
	return 0;
}

