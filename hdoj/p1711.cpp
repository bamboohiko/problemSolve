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
int a[1001000],b[10010],nextb[10010];
int main()
{
	int t,m,n;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&m,&n);
		for (int i = 1;i <= m; i++) scanf("%d",&a[i]);
		for (int i = 1;i <= n; i++) scanf("%d",&b[i]);
		nextb[0] = -1;nextb[1] = 0;
		for (int i = 2;i <= n; i++)
		{
			int j = nextb[i-1];
			while (j >= 0 && b[j+1] != b[i]) j = nextb[j];
			nextb[i] = j+1;
		}
		int j = 0,ans = -1;
		for (int i = 1; i <= m; i++)
		{
			while (j >= 0 && b[j+1] != a[i]) j = nextb[j];
			++j;
			if (j == n)
			{
				ans = i-n+1;
				break;
			} 
		}
		printf("%d\n",ans);
	}
	return 0;
}
