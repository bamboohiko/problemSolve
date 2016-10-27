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
int f[20][40000],d[20],c[20],n;
string st[20];
int day(int k)
{
	int ans = 0,loc = n;
	while (k)
	{
		if (k%2 == 0) ans += c[loc];
		k /= 2;
		loc--;
	}
	return ans;
}
int dfs(int v,int k)
{
	if (f[v][k] >= 0) return f[v][k];
	for (int i = n-1;i >= 0;i++)
		if (1 << i & k)
		{
			int t = dfs(v+1,k - 1 << i) + max(0,day(k)-d[i]);
			if (f[v][k] == -1 || t < f[v][k]) f[v][k] = t;
		}
	return f[v][k]; 
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n; i++)
			cin >> st[i] >> d[i] >> c[i];
		memset(f,-1,sizeof(f));f[n][0] = 0;
		int t = 1 << n;
		cout << dfs(0,t - 1) << endl;
	}
	return 0;
}
