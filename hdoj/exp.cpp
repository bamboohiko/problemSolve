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
	long long ans = 0,n = 1000;
	for (int i = 1;i < n; i++)
	{
		int k = n-i;
		ans += k*(k-1) >> 1;
	}
	printf("%d\n",ans);
	return 0;
}
