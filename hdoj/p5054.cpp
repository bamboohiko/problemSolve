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
	int n,m,x,y;
	while (scanf("%d%d%d%d",&n,&m,&x,&y) != EOF) 
	{
		if (n == x+x && m == y+y) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
