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
	while (scanf("%d %d",&n,&m) != EOF && (n != -1 || m != -1))
	{
		 if (gcd(n,m) > 1) printf("POOR Haha\n");
		 else printf("YES\n");
	}
	return 0;
}
 
