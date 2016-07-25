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
const int INF = 1e9;
int a[2010];
int f[2010][1010];
int main()
{
	int n,k;
	while (scanf("%d%d",&n,&k) != EOF)
	{
		for (int i = 1;i <= n; i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		for (int j = 1;j <= k; j++)
		{
			int t = (a[j+j]-a[j+j-1])*(a[j+j]-a[j+j-1]);			
			f[j+j][j] = f[j+j-2][j-1] + t; 
			for (int i = j+j+1;i <= n; i++)	
			{
				t = (a[i] - a[i-1])*(a[i] - a[i-1]);
				f[i][j] = min(f[i-2][j-1]+t,f[i-1][j]);		
			}
		}
		printf("%d\n",f[n][k]);
	}
	return 0;
}
