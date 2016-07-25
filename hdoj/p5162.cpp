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
struct jump{
	int x,dis;
};
jump rec[10];
bool cmp(jump a,jump b)
{
	return a.dis > b.dis;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		int a,b,c;
		for (int i = 1;i <= n; i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			rec[i].dis = max(a,max(b,c));
			rec[i].x = i;
		}
		sort(rec+1,rec+n+1,cmp);
		for (int i = 1;i < n; i++)
			printf("%d ",rec[i].x);
		printf("%d\n",rec[n].x);
	}
	return 0;
}

