#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int a[300100],lazy[300100];
void build(int l,int r,int pos)
{
	if (l == r) {
		scanf("%d",&a[pos]);
		return;
	}
	int mid = (l+r) >> 1;
	build(l,mid,pos*2);
	build(mid+1,r,pos*2+1);
	a[pos] = a[pos*2] + a[pos*2+1];
}
void add(int l,int r,int pos,int x,int y,int num)
{
	if (x <= l && r <= y)
		{lazy[pos] = num;
		a[pos] = num*(r-l+1);
		return;
		}
	int mid = (l+r) >> 1;
	if (lazy[pos])
		{lazy[pos*2] = lazy[pos];
		a[pos*2] = lazy[pos]*(mid-l+1);
		lazy[pos*2+1] = lazy[pos];
		a[pos*2+1] = lazy[pos]*(r-mid);
		lazy[pos] = 0;
		}
	if (x <= mid) add(l,mid,pos*2,x,y,num);
	if (y > mid) add(mid+1,r,pos*2+1,x,y,num);
	a[pos] = a[pos*2] + a[pos*2+1];
}
int sum(int l,int r,int pos,int x,int y)
{int s1 = 0,s2 = 0;
	if (x <= l && r <= y)
		return a[pos];
	int mid = (l+r) >> 1;
	if (lazy[pos])
		{lazy[pos*2] = lazy[pos];
		a[pos*2] = lazy[pos]*(mid-l+1);
		lazy[pos*2+1] = lazy[pos];
		a[pos*2+1] = lazy[pos]*(r-mid);
		lazy[pos] = 0;
		}
	if (x <= mid) s1 = sum(l,mid,pos*2,x,y);
	if (y > mid) s2 = sum(mid+1,r,pos*2+1,x,y);
	return s1+s2;
}
int main()
{int m,n,t;
	scanf("%d",&n);
	build(1,n,1);
	scanf("%d",&m);
	for (int i = 1;i <= m; i++)
		{int t,x,y,num;
		scanf("%d%d%d",&t,&x,&y);
		if (t) 
			{scanf("%d",&num);
			add(1,n,1,x,y,num);
			}
		else
			printf("%d\n",sum(1,n,1,x,y));
		}
	return 0;
}
