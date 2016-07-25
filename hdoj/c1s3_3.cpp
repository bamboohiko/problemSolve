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
struct dat{
	int l,m;
};
dat a[60];
bool cmp(dat a,dat b)
{
	return a.l < b.l;
}
int main()
{
	string s1 = ">+",s2 = "+>";
	int t,n;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i = 0;i < n; i++)
			scanf("%d%d",&a[i].l,&a[i].m);
		sort(a,a+n,cmp);	
		for (int k = 0;k < n; k++)
		{
			for (int i = 1;i <= a[k].m; i++)
			{
				cout << s1;
				for (int j = 1;j <= a[k].l-2; j++) printf("-");
				cout << s2;
				printf("\n");
			}
			printf("\n");
		}
	}
	return 0;
}
