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
int a[1010],b[1010];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF && n)
	{
		for (int i = 0;i < n; i++) scanf("%d",&a[i]);
		for (int i = 0;i < n; i++) scanf("%d",&b[i]);
		sort(a,a+n);sort(b,b+n);
		int ans = 0,op = 0,ed = n-1;
		for (int i = 0,j = n-1;i <= j;i++)
		{
			if (a[i] != b[op])
			{
				if (a[i] > b[op]) 
				{
					op++;ans++;
				}
				else 
				{
					ed--;ans--;
				}
			}
			else
			{
				while (a[j] > b[ed])
				{
					j--;ed--;ans++;
				}
				if (a[j] < b[ed] || (a[j] == b[ed] && a[j] > a[i]))
					ans--; 
				ed--;
			}
		}
		printf("%d\n",ans*200);
	}
	return 0;
}
