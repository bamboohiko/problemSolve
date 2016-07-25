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
int f[100000 + 10];
set<int> use;
int add(int x)
{
	if (!use.count(x)) 
	{
		use.insert(x);
		return 1;
	}
	return 0;
}
int main()
{
	int x,y,t = 0;
	while (scanf("%d%d",&x,&y) != EOF && x >= 0 && y >= 0)
	{
		printf("Case %d is ",++t);
		if (!x || !y) 
		{
			printf("not a tree.\n");
			continue;
		}
		use.clear();
		int cou = 1,n = add(x) + add(y),ans = 1;
		memset(f,0,sizeof(f));
		if (x == y) ans = 0;
		while (scanf("%d%d",&x,&y) != EOF && x && y)
		{
			cou++;
			n += add(x) + add(y);
			f[y]++;
			if (f[y] > 1) ans = 0;
		}
		if (cou != n-1) ans = 0;
		if (!ans) printf("not ");
		printf("a tree.\n");
	}
	return 0;
}
