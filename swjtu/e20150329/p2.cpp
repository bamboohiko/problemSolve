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
const int INF = 2e9 + 7;
int sum[1010],n;
int fig(int l,int r)
{
	if (r >= l) return sum[r-1] - sum[l-1];
	return sum[n] - sum[l-1] + sum[r-1];
}
int main()
{
	int t;
	scanf("%d",&t);
	for (int ca = 1;ca <= t; ca++)
	{
		printf("Case #%d:",ca);
		scanf("%d",&n);
		for (int i = 1;i <= n; i++)
		{
			scanf("%d",&sum[i]);
			sum[i] += sum[i-1];
		}
		for (int i = 1;i <= n; i++)
		{
			int k1,k2,ans = INF;
			for (int j = 1;j <= n; j++)
			{
				k1 = fig(i,j);
				k2 = fig(j+1,i);
				ans = min(ans,k1 + k2 + min(k1,k2));
			}
			printf(" %d",ans);
		}
		printf("\n");
	}
	return 0;
}
