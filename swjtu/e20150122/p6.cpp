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
int f[10000 + 10];
vector<int> edge[10000 + 10];
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF)
	{
		memset(cou,0,sizeof(cou));
		for (int i = 1;i <= n; i++) 
		{
			f[i] = i;
			s[i] = 1;
		}
		for (int i = 1;i <= m; i++)
		{
			int x,y;char ch;
			scanf("%d %c %d",&x,&ch,&y);
			x = find(x);y = find(y);
			if (ch == '=' && x != y)
			{
				f[x] = y;
				for (vector<int>::iterator i = edge[x].begin();i < edge[x].end(); ++i)
					edge[y].push_back(*i);
				edge[x].resize(0);
				cou[y] += cou[x];
				s[y] += s[x];
			} 
			if (ch == '<') 
			{
				edge[x].push_back(y);
				cou[y]++;
			}
			if (ch == '>') 
			{
				edge[y].push_back(x);
				cou[x]++;
			}
		}
		queue<int> Q;
		memset(use,0,sizeof(use));
		for (int i = 1;i <= n; i++) 
			{
				int x = find(i);
				if !(cou[x] || use[x]) Q.push(x);
 			}
 		int key = n;
		while (Q.size() == 1)
		{
			int x = Q.front(); Q.pop();
			for (vector<int>::iterator i = edge[x].begin();i < edge[x].end(); ++i)
			{
				cou[*i]--;
				if (!cou[*i]) Q.push(*i);
				if (cou[*i])
				{
					key = -1;
					break;
				}	
			}
			if (key = -1) break;
			key -= cou[x];	
		}
		if (key > 0) printf("")
	}
	return 0;
}
