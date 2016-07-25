#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int p[300100],lazy[300100];
void build(int l,int r,int pos)
{
	if (l == r) 
		{scanf("%d",p+pos);
		return;
		}
	int mid = (l+r) >> 1;
	build(l,mid,pos*2);
	build(mid+1,r,pos*2+1);
	p[pos] = p[pos*2]+p[pos*2+1];
}
void change(int l,int r,int pos,int x,int y,int w)
{
	if (l >= x && r <= y)
		{lazy[pos] = w;
		p[pos] = w*(r-l+1);
		return;
		}
	int mid = (l+r) >> 1;
	if (lazy[pos]) 
		{lazy[pos*2] = lazy[pos];
		p[pos*2] = lazy[pos]*(mid-l+1);
		lazy[pos*2+1] = lazy[pos];
		p[pos*2+1] = lazy[pos]*(r-mid);
		lazy[pos] = 0;
		}
	if (x <= mid) change(l,mid,pos*2,x,y,w);
	if (y > mid) change(mid+1,r,pos*2+1,x,y,w);
	p[pos] = p[pos*2]+p[pos*2+1];
}
int ask(int l,int r,int pos,int x,int y)
{int ans = 0;
	if (l >= x && r <= y) return p[pos];
	int mid = (l+r) >> 1;
	if (lazy[pos]) 
		{lazy[pos*2] = lazy[pos];
		p[pos*2] = lazy[pos]*(mid-l+1);
		lazy[pos*2+1] = lazy[pos];
		p[pos*2+1] = lazy[pos]*(r-mid);
		lazy[pos] = 0;
		}
	if (x <= mid) ans += ask(l,mid,pos*2,x,y);
	if (y > mid) ans += ask(mid+1,r,pos*2+1,x,y);
	return ans; 
}
int main()
{int n,q;
	cin >> n;
	build(1,n,1);
	cin >> q;
	for (int i = 1;i <= q; i++)
		{int t,l,r,v;
		scanf("%d%d%d",&t,&l,&r);
		if (t) 
			{scanf("%d",&v);
			change(1,n,1,l,r,v);
			}
		else printf("%d\n",ask(1,n,1,l,r));
		}
	return 0;
}
