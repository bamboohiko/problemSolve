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
long long  f[60];
int main()
{
	f[0] = 1;f[1] = 1;
	for (int i = 2;i <= 50; i++)
		f[i] = f[i-1] + f[i-2];
	int n;
	while (scanf("%d",&n) != EOF)
		printf("%I64d\n",f[n]);
	return 0;
}
