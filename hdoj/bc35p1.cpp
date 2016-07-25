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
typedef long long LL;
LL can(int a,int b)
{
	LL up = 1,down = 1;
	for (int i = 1;i <= b; i++)
	{
		up *= (a+i-b);
		down *= i;
	}
	return up/down;
}
LL gcd(LL a,LL b)
{
	while (b)
	{
		LL t = a;a = b;b = t%b;
	}
	return a;
}
int main()
{
	
	int p,q;
	while (scanf("%d%d",&p,&q) != EOF)
	{
		LL t1 = 0,t2 = can(q+p,q);
		for (int i = 1;i <= min(p,q); i++)
			t1 += i*can(q,i);
		LL k = gcd(t1,t2);
		printf("%I64d/%I64d\n",t1/k,t2/k);
	}
	return 0;
}
