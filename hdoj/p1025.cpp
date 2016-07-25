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
struct dat{
	int x,y;
};
const int INF = 1e7;
dat a[500100];
int f[500100];
bool cmp(dat a,dat b)
{
	return a.x < b.x;
}
int main()
{
	int n,t = 0;
	while (scanf("%d",&n) != EOF)
	{
		printf("Case %d:\n",++t);
		for (int i = 0;i < n; i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		sort(a,a+n,cmp);
		for (int i = 0;i <= n; i++) f[i] = INF;
		int ans = 1; 
		for (int i = 0;i < n; i++)
			{
				int t = lower_bound(f+1,f+i+1,a[i].y) - f;
				ans = max(ans,t);
				f[t] = a[i].y;
			}
 		if (ans == 1) printf("My king, at most %d road can be built.\n\n",ans);
 		else printf("My king, at most %d roads can be built.\n\n",ans);
	}
	return 0;
}
