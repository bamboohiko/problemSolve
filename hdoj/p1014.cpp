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
	int s,m;
	while (scanf("%d%d",&s,&m) != EOF)
	{
		printf("%10d%10d    ",s,m);
		if (gcd(s,m) > 1) printf("Bad Choice\n");
		else printf("Good Choice\n");
		printf("\n");
	}
	return 0;
}
