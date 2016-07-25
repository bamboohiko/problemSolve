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
struct line{
	int x,y;
};
map<int,int> f;
set<int> ans;
vector<int> sav;
int tree[800100];
line a[100100];
void add(int x)
{
	if (!f.count(x))
	{
		f[x] = 0;
		f[x] = f.size();
	}
}
void updata(int l,int r,int p,int x,int y,int num)
{
	if (x <= l && r <= y)
	{
		tree[p] = num;
		return;
	}
	int mid = (l + r) >> 1;
	if (tree[p])
		tree[p*2] = tree[p*2+1] = tree[p];
	if (x <= mid) updata(l,mid,p*2,x,y,num);
	if (y > mid) updata(mid+1,r,p*2+1,x,y,num);
	if (tree[p*2] == tree[p*2+1]) tree[p] = tree[p*2];
	else tree[p] = 0;
}
void cou(int l,int r,int p)
{
	//printf("%d %d %d\n",l,r,tree[p]);
	if (tree[p])
	{
		if (!ans.count(tree[p])) ans.insert(tree[p]);
		return;
	}
	int mid = (l + r) >> 1;
	cou(l,mid,p*2);
	cou(mid+1,r,p*2+1);
}
int main()
{
	int n,m,l;
	scanf("%d%d",&n,&l);
	for (int i = 0;i < n; i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		sav.push_back(a[i].x);
		sav.push_back(a[i].y);
	}
	sort(sav.begin(),sav.end());
	for (vector<int>::iterator i = sav.begin();i != sav.end(); ++i)
		add(*i);
	m = f.size();
	for (int i = 0;i < n; i++)
	{
		updata(1,m,1,f[a[i].x],f[a[i].y],i+1);
		//cout << f[a[i].x] << " " <<  f[a[i].y] << endl;
	}
	cou(1,m,1);
	printf("%d\n",ans.size());
	return 0;
}

