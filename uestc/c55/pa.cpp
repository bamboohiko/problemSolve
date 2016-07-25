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
set<int> dic;
int main()
{
	int n,k,ok = 0;
	dic.clear();
	scanf("%d",&n);
	for (int i = 1;i <= n; i++) 
	{
		scanf("%d",&k);
		if (!k || dic.count(-k))
		{
			ok = 1;
			break;
		}
		dic.insert(k);
 	}
 	if (ok) printf("NOT UNIQUE\n");
 	else printf("UNIQUE\n");
	return 0;
}
