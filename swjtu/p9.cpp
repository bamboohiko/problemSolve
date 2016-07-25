#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int p[1300];
int rec[510][1300];
int cou[1300];
vector<int> ans[10010];
int vis[10010]
int main()
{int n = 10000,sum = 0;
	for (int i = 2;i <= n; i++)
		if (!vis[i])
			for (int j = i+i;j <= n; j+=i)
				vis[j] = 1;
	for (int i = 2;i <= n; i++)
		if (!(vis[i])) 
			p[++sum] = i;
	while (cin >> n)
		{ans.clear();
		memset(rec,0,sizeof(rec));
		memset(cou,0,sizeof(cou));
		for (int i = 1;i <= n; i++)
			{int x;
			cin >> x;
				for (int j = 1;j <= 25; j++)
					{while (!(x%p[j])) rec[i][p[j]]++;
					if (rec[i][p[j]]) vis[j].push_back(i);
					cou[p[j]] = min(cou[p[j]],rec[i][p[j]]);
					}
				rec[i][x]++;
			}
		for (int i = 1;i <= 10000; i++)
			{for (int j = 1;j <= vis)
			}
		}
	return 0;
}
