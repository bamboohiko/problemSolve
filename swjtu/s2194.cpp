#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int pri[] = {3,5,7,11,13,17,19,23,29,31,37};
int use[30],num[30],n,ans = 0;
void print()
{
	for (int i = 1;i < n; i++) 
		printf("%d ",num[i]);
	printf("%d\n",num[n]);
}
bool prime(int k)
{
	for (int i = 0;i <= 10; i++)
		if (k == pri[i]) return true;
	return false;
}
void dfs(int k)
{
	if (k == n)
		{if ( prime(num[n]+1) ) print();
		return;
		}
	for (int i = 2;i <= n; i++)
		if (!use[i] && prime( i+num[k] ) )
			{use[i] = 1;
			num[k+1] = i;
			dfs(k+1);
			use[i] = 0;
			}
} 
int main()
{int t = 0;
	while (cin >> n)
		{printf("Case %d:\n",++t);
		memset(use,0,sizeof(use));
		num[1] = 1;
		dfs(1);
		printf("\n");
		}
	return 0;
}
