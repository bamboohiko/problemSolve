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
long long f[60];
int main()
{
	long long mul = 2;
	f[1] = 3;f[2] = 6;
	for (int i = 3;i <= 50; i++)
		f[i] = 3*(mul*=2) - f[i-1]; 
	int n;
	while (scanf("%d",&n) != EOF)
		printf("%I64d\n",f[n]);
	return 0;
}
