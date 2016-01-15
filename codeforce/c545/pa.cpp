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
bool vis[110];
vector<int> sav;
int main()
{
	int n,k;
	scanf("%d",&n);
	for (int i = 1;i <= n; i++) 
		for (int j = 1;j <= n; j++) {
			scanf("%d",&k);
			if (k == 1 || k == 3) vis[i] = true;
		}
	int ans = 0;
	for (int i = 1;i <= n; i++) 
		if (!vis[i]) {
			ans++;
			sav.push_back(i);
		}
	printf("%d\n",ans);
	if (sav.size()) {
		printf("%d",sav[0]);
	for (int i = 1;i < sav.size(); i++)
		printf(" %d",sav[i]);
	printf("\n");
	}
	return 0;
}
