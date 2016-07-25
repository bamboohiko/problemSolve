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
int gcd(int a,int b)
{
	while (b)
	{
		int t = a;a = b;b = t%b;
	}
	return a;
}
int main()
{
	int n,m;
	int a,b;
	while (scanf("%d%d",&n,&m) != EOF)
	{
		a = n*m;
		b = n+m;
		int k = gcd(a,b);
		printf("%d/%d\n",a/k,b/k);
	}
	return 0;
}
