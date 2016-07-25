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
set<int> dic;
int sum[1000100];
int main()
{
	int t;
	sum[0] = 0;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&k);
		int sig = 1,now;
		for (int i = 1;i <= n; i++)
		{
			scanf("%d",&now);
			sum[i] = sum[i-1] + sig*now;
			sig *= -1;	
		}
		dic.clear();
		for (int i = 1;i <= n; i++)
		{
			
		}
	}
	return 0;
}
