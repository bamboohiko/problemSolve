#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int f[100010];
int find(int x)
{vector<int> s;
	while (x != f[x])
		{s.push_back(x);
		x = f[x];
		}
	while (!s.empty())
		{f[s.back()] = x;
		s.pop_back();
		}
	return x;
}
int main()
{int n,m;
	while (scanf("%d%d",&n,&m) != EOF)
		{for (int i = 1;i <= n; i++) f[i] = i;
		for (int i = 1;i <= m; i++)
			{int a,b;
			cin >> a >> b;
			f[a] = max(f[a],find(f[b]));
			}
		for (int i = 1;i < n; i++) printf("%d ",find(f[i]));
		printf("%d\n",f[n]);
		}
	return 0;
}
