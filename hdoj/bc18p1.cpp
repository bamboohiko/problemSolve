#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
using namespace std;
const int M = 10000;
int vis[10010];
int prime[2000];
set<int> s;
vector<int> v;
int main()
{int n;
	memset(vis,0,sizeof(vis));
	for (int i = 2;i <= M; i++)
		if (!vis[i])
			{for (int j = i+i;j <= M; j+=i)
				vis[j] = 1;
			s.insert(i);
			v.push_back(i);
			}
	/*for (int i = 0;i < v.size(); i++)
		printf("%d ",v[i]);printf("/n");
	*/
	while (scanf("%d",&n) != EOF)
		{int ans = 0;
		for (int i = 0;i < v.size(); i++)
			{if (v[i] >= n) break;
			for (int j = i;j < v.size(); j++)
				if (n-v[i]-v[j] < v[j]) break;
				else if (s.count(n-v[i]-v[j]))
					{ans++;
					//printf("%d %d %d\n",v[i],v[j],n-v[i]-v[j]);
					}
			}
		printf("%d\n",ans);
		}
	return 0;
}
