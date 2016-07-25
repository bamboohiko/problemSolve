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
	string name;
	int sum;
};
dat sav[1010];
int s[20];
bool cmp(dat a,dat b)
{
	if (a.sum != b.sum) return a.sum > b.sum;
	return a.name < b.name;
}
int main()
{
	int n,m,g;
	while (scanf("%d",&n) != EOF && n)
	{
		scanf("%d%d",&m,&g);
		for (int i = 1;i <= m; i++)
			scanf("%d",&s[i]);
		for (int i = 0;i < n; i++)
		{
			cin >> sav[i].name;
			sav[i].sum = 0;
			int t,k;
			scanf("%d",&t);
			for (int j = 0;j < t; j++)
			{
				scanf("%d",&k);
				sav[i].sum += s[k];
			}
		}
		sort(sav,sav+n,cmp);
		int pas = 0;
		for (pas = 0;pas < n; pas++)
			if (sav[pas].sum < g) break;
		printf("%d\n",pas);
		for (int i = 0;i < pas; i++)	
		  cout << sav[i].name << " " << sav[i].sum << endl;
	}
	return 0;
}
