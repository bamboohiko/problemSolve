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
	freopen("test1.out","w",stdout);
	int n = 1000;
	int mod = 1e9;
	printf("%d\n",n);
	for (int i = 1;i <= n; i++)
	{	
		int sig = rand()%2?1:-1;
		int k = sig*rand()*rand()%mod;
		printf("%d %d\n",k,k);
	}
	return 0;
}
