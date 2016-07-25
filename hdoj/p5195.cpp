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
vector<int> G[100100];
int sav[100100],rec[100100];
int main()
{
	int n,m,k;
	while (scanf("%d%d%d",&n,&m,&k) != EOF)
	{
		for (int i = 1;i <= n; i++) G[i].clear();
		memset(rec,0,sizeof(rec));
		int from,to;
		for (int i = 1;i <= m; i++)
		{
			scanf("%d%d",&from,&to);
			G[from].push_back(to);
			rec[to]++;
		}
		priority_queue<int> Q;
		for (int i = 1;i <= n; i++)
			if (!rec[i]) Q.push(i);
		while (!Q.empty())
		{
			int s = Q.top();Q.pop();
			for (int i = 0;i < G[s].size(); i++)
			{
				int t = G[s][i];
				rec[t]--;
				if (rec[0])
			}
		}
	}
	return 0;
}
