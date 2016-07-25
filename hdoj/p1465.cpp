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
long long f[30];
int main()
{
	f[1] = 0;f[2] = 1;
	for (int i = 3;i <= 20; i++) 
	{
		f[i] = (i-1)*(f[i-1]+f[i-2]);
		//cout << i << " " << f[i] << endl;
	}
	int n;
	while (scanf("%d",&n) != EOF)
		printf("%I64d\n",f[n]);
	return 0;
}
