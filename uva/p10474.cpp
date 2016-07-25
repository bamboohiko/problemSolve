#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{int n,m,t,k,con=0;
	while (cin >> n >> m)
		{vector<int> v;
		for (int i = 1;i <= n; i++)
			{cin >> t;
			v.push_back(t);
			}
		sort(v.begin(),v.end());
		printf("Case# %d\n",++con);
		for (int i = 1;i <= m; i++)
			{cin >> t;
			k=lower_bound(v.begin(),v.end(),t)-v.begin();
			//cout << v[k] << endl;
			if (v[k] == t) printf("%d found at %d\n",t,k+1);
			else printf("%d not found\n",t);
			}
		}
	return 0;
}
