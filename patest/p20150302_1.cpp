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
	int n,num = 0,sum = 0,ans = 0;
	scanf("%d",&n);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d",&num);
		sum = max(0,sum) + num;
		ans = max(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}

