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
vector<char> a;
bool cmp(char a,char b)
{
	return a > b;
}
int main()
{
	int n,k;
	while (scanf("%d",&n) != EOF)
	{
		a.clear();
		for (int i = 0;i < n; i++)
		{
			scanf("%d",&k);
			a.push_back('0' + k);
		}
		sort(a.begin(),a.end(),cmp);
		int ok = 0;
		for (int i = a.size()-1;i >= 0; i--)
			if (a[i]%2) 
			{
				char mid = a[i];
				a.erase(a.begin() + i);
				a.push_back(mid);
				ok = 1;
				break;
			}
		if (ok && a[0] != '0')
		{
			for (int i = 0;i < a.size(); i++)
				printf("%c",a[i]);
			printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}
