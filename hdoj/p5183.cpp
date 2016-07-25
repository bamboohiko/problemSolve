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
long long sum[1000100];
set<long long> dic;
int main()
{
	int t,n;
	scanf("%d",&t);
	for (int cas = 1;cas <= t; cas++)
	{
		long long num,k;
		printf("Case #%d: ",cas);
		scanf("%d%I64d",&n,&k);
		int sig = 1,ok = 0;
		for (int i = 1;i <= n; i++)
		{
			scanf("%I64d",&num);
			sum[i] = sum[i-1] +sig*num;
			sig *= -1;
		}
		dic.clear();
		dic.insert(0);
		if (!ok)
			for (int i = 1;i <= n; i++)
			{
				if (dic.count(sum[i] - k)) 
				{
					ok = 1;
					break;
				}
				if (i%2 == 0) dic.insert(sum[i]);
			}
		dic.clear();
		dic.insert(-sum[1]);
		if (!ok)
			for (int i = 2;i <= n; i++)
			{
				sum[i] *= -1;
				if (dic.count(sum[i] - k))
				{
					ok = 1;
					break;
				}
				if (i%2) dic.insert(sum[i]);
			}
		if (ok) printf("Yes.\n");
		else printf("No.\n");
	}
	return 0;
}
