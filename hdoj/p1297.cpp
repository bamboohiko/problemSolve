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
long long f[1010][2];
int main()
{
	f[0][0] = 1;f[1][0] = 1;
	for (int i = 2;i <= 1000; i++)
	{
		f[i][0] = f[i-1][0] + f[i-1][1];
		f[i][1] = f[i-1][1] + f[i-2][0];
	}
	int n;
	while (scanf("%d",&n) != EOF)
		printf("%I64d\n",f[n][0] + f[n][1]);
	return 0;
}
