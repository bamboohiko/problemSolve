#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int f[1010],p[1010],v[1010];
int main()
{int t;
	cin >> t;
	while (t--)
		{int n,m,ans = 0;
		memset(f,0,sizeof(f));
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n; i++) scanf("%d",&p[i]);
		for (int i = 1;i <= n; i++) scanf("%d",&v[i]);
		for (int i = 1;i <= n; i++)
			for (int j = m; j >= v[i]; j--)
				{f[j] = max(f[j],f[j-v[i]]+p[i]);
				ans = max(f[j],ans);
				}
		cout << ans << endl;
		}
	
	return 0;
}
