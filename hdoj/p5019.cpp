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
int a[1001000];
long long gcd(long long a,long long b)
{
	while (b)
	{
		long long t = a;a = b;b = t%b;
	}
	return a;
}
long long pow2(int x)
{
	long long ans = x;
	return ans*ans;
}
int main()
{
	int t;
	a[1] = 1;
	long long x,y,k,ans;
	scanf("%I64d",&t);
	while (t--)
	{
		scanf("%I64d%I64d%I64d",&x,&y,&k);
		x = gcd(x,y);
		int s = 1,sum;
		for (int i = 2;pow2(i) <= x; i++)
			if (x%i == 0) 
				a[++s] = i;
		sum = s+s;
		if (a[s]*a[s] == x) sum--;
		if (k > sum) ans = -1;
		else 
		{
			if (k <= s) ans = x/a[k];
			else ans = a[sum+1-k];
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
