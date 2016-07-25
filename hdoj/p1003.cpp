#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100010],f[100010];
int main()
{int n,m;
	cin >> n;
	for (int nt = 1;nt <= n; nt++)
		{printf("Case %d:\n",nt);
		scanf("%d%d",&m,a+1);
		int ans = f[1] = a[1],loc = 1;
		for (int i = 2;i <= m; i++)
			{scanf("%d",a+i);
			f[i] = max(0,f[i-1])+a[i];
			if (f[i] > ans) 
				{ans = f[i];
				loc = i;
				}
			}
		int from = loc-1;
		while (from && f[from]+a[from+1] == f[from+1]) from--;
		printf("%d %d %d\n",ans,from+1,loc);
		if (nt != n) printf("\n");
		}
	return 0;
}
