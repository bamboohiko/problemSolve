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
int f[550][550];
int main()
{
	int n,m,b,mod,v;
	scanf("%d%d%d%d",&n,&m,&b,&mod);
	f[0][0] = 1;
	for (int i = 0;i < n; i++) {
		scanf("%d",&v);
		for (int j = 1;j <= m; j++)
			for (int k = v;k <= b; k++)
				f[j][k] = (f[j][k] + f[j-1][k-v])%mod;
	}
	int ans = 0;
	for (int i = 0;i <= b; i++) 
		ans = (ans + f[m][i])%mod;
		printf("%d\n",ans);
	return 0;
}
