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
bool vis[2020];
int f[2020];
vector<int> edge[2020];
void dfs(int x,int k) {
	for (int i = 0;i < edge[x].size(); i++) {
		int p = edge[x][i];
		f[p] = k;
		if (!vis[p]) {
			vis[p] = true;
			dfs(p,k);
		}
	}
}
int main()
{
	int n;
	while (scanf("%d",&n) != EOF) {
		memset(vis,0,sizeof(vis));
		for (int i = 1;i <= n; i++) {
			f[i] = i;
			edge[i].clear();
		}
		int k;
		for (int i = 1;i <= n; i++) {
			while (scanf("%d",&k) != EOF && k) {
				edge[i].push_back(k);
			}
		}
		for (int i = 1;i <= n; i++) {
			if (f[i] != i) continue;
			memset(vis,0,sizeof(vis));
			vis[i] = true;
			dfs(i,i);
		}
		int ans = 0;
		set<int> dic;
		for (int i = 1;i <= n; i++) 
			dic.insert(f[i]);
		printf("%d\n",dic.size());
	}
	return 0;
}
