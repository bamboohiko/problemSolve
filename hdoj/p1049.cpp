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
	int n,u,d;
	while (scanf("%d%d%d",&n,&u,&d) != EOF && n)
	{
		int ans = 0;
		while (n > u)
		{
			ans += 2;
			n -= u-d;
		}
		if (n) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
