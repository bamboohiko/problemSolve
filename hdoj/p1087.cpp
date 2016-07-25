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
int a[1010],f[1010];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF && n)
	{
		int ans = 0;
		for (int i = 1;i <= n; i++)
		{
			scanf("%d",&a[i]);
			f[i] = 0;
			for (int j = 1;j < i; j++)
				if (a[i] > a[j] && f[j] > f[i])
					f[i] = f[j];
			f[i] += a[i];
			ans = max(ans,f[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
