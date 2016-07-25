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
int main()
{
	int n,m,v,p,cost;
	while (scanf("%d%d",&n,&m) != EOF)
	{
		int ans = 1e6;
		for (int i = 0;i < m; i++)
		{
			scanf("%d%d",&v,&p);
			cost = p*(n/v);
			if (n%v) cost += p;
			ans = min(ans,cost);
		}
		printf("%d\n",ans);
	}
	return 0;
}
