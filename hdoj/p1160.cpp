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
const int INF = 1e6;
struct dat{
	int w,s,num;
};
dat a[1010];
int f[1010],d[1010];
bool cmp(dat a,dat b)
{
	if (a.w != b.w) return a.w < b.w;
	return a.s < b.s;
}
void dfs(int k)
{
	if (f[k] > 1) dfs(d[k]);
	printf("%d\n",a[k].num);
}
int main()
{
	int n = 1;
	while (scanf("%d%d",&a[n].w,&a[n].s) != EOF) 
	{
		a[n].num = n;n++;
	}
	sort(a+1,a+n,cmp);
	int ans = 0,loc = 0;
	for (int i = 1;i < n; i++)
	{
		f[i] = 1;
		for (int j = 1;j < i; j++)
			if (a[i].s < a[j].s && f[j] >= f[i])
			{
				f[i] = f[j]+1;
				d[i] = j;
			}
		if (f[i] > ans) 
		{
			ans = f[i];
			loc = i;
		}
	}
	printf("%d\n",ans);
	dfs(loc);
	return 0;
}
