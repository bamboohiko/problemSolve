#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int p[3000100];
void build(int l,int r,int pos)
{
	if (l == r) 
		{cin >> p[pos];
		return;
		}
	int mid = (l+r) >> 1;
	build(l,mid,pos*2);
	build(mid+1,r,pos*2+1);
	p[pos] = min(p[pos*2],p[pos*2+1]);
}
void change(int l,int r,int pos,int loc,int w)
{
	if (l == r)
		{p[pos] = w;
		return;
		}
	int mid = (l+r) >> 1;
	if (loc <= mid) change(l,mid,pos*2,loc,w);
	else change(mid+1,r,pos*2+1,loc,w);
	p[pos] = min(p[pos*2],p[pos*2+1]);
}
int ask(int l,int r,int pos,int x,int y)
{int ans = 1 << 30;
	if (l >= x && r <= y) return p[pos];
	int mid = (l+r) >> 1;
	if (x <= mid) ans = min(ans,ask(l,mid,pos*2,x,y));
	if (y > mid) ans = min(ans,ask(mid+1,r,pos*2+1,x,y));
	return ans; 
}
int main()
{int n,q;
	cin >> n;
	build(1,n,1);
	cin >> q;
	for (int i = 1;i <= q; i++)
		{int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		if (t) change(1,n,1,l,r);
		else printf("%d\n",ask(1,n,1,l,r));
		}
	return 0;
}
