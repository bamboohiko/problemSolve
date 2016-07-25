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
	int n,x,y,z;
	scanf("%d",&n);
	for (int ca = 1;ca <= n; ca++)
	{
		scanf("%d%d%d",&x,&y,&z);
		printf("Scenario #%d:\n",ca);
		if (x < y) swap(x,y);
		if (x < z) swap(x,z);
		if (x*x == y*y + z*z) 
			printf("yes\n");
		else 
			printf("no\n");
		printf("\n");
	}
	return 0;
}

