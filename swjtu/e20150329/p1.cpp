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
	int n,s,t;
	scanf("%d",&n);
	for (int ca = 1;ca <= n; ca++)
	{
		int ans = 0;
		scanf("%d%d",&s,&t);
		while (3*s + 1 <= t)
		{
			ans += s;
			s = 3*s + 1;
		}
		ans += (t-s) >> 1;
		printf("Case #%d: %d\n",ca,ans);
	}
	return 0;
}
