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
const int INF = 1e7;
map<char,int> dic;
vector<int> sav[100];
int num[10100],f[10100];
int main()
{
	string a,b;
	while (cin >> a >> b)
	{
		int n = 0,m = 0,ans = 0;
		for (int i = 0;i < a.length(); i++)
			if (!dic.count(a[i])) dic[a[i]] = n++;
		for (int i = b.length()-1;i >= 0; i--)
			if (dic.count(b[i])) sav[dic[b[i]]].push_back(i);
		for (int i = 0;i < a.length(); i++)
		{
			int t = dic[a[i]];
			for (int j = 0;j < sav[t].size(); j++)
				num[m++] = sav[t][j];
		}
		for (int i = 1;i <= m; i++) f[i] = INF;
		for (int i = 0;i < m; i++)
		{
			int t = lower_bound(f+1,f+ans+1,num[i]) - f;
			ans = max(ans,t);
			f[t] = num[i];
		} 
		printf("%d\n",ans);
		dic.clear();
		for (int i = 0;i < n; i++) sav[i].clear();
	}
	return 0;
}
