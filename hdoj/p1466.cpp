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
int a[25][2100];
int main()
{
	int n;
	a[1][0] = 1;
	while (scanf("%d",&n) != EOF)
	{
		for (int i = 1;i <= n; i++)
		{
			if (a[i][0]) continue;
			a[i][0] = 1;
			for (int j = 1;j < i; j++)
			{
				int t = (i - j)*j;
				for (int k = 1;k <= a[j][0]; k++)
					a[i][++a[i][0]] = a[j][k] + t;
			}
			sort(a[i]+1,a[i]+a[i][0]+1);	
			for (int j = 1;j <= a[i][0]; j++)
				while (a[i][j] == a[i][j-1])
				{
					for (int k = j;k < a[i][0]; k++)
						a[i][k] = a[i][k+1];
					a[i][0]--;
				}
		}
		printf("%d",a[n][1]);
		for (int i = 2;i <= a[n][0]; i++)
			printf(" %d",a[n][i]);
		printf("\n");
	}
	return 0;
}
