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
int f[80][80][80];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		memset(f,0,sizeof(f));
		f[0][0][0] = 1;
		for (int i = 1;i <= n; i++)
			for (int j = 0;j <= i; j++)
				for (int k = 0;k <= j; k++)
				{
					f[i][j][k] = 0;
					if (i > j) f[i][j][k] += f[i-1][j][k];
					if (j > k) f[i][j][k] += f[i][j-1][k];
					f[i][j][k] += f[i][j][k-1];
				}
		printf("%d\n\n",f[n][n][n]);
	}
	return 0;
}
