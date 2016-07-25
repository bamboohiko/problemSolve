#include<iostream>
using namespace std;
int f[110];
int find(int x)
{
	if (f[x] != x) return f[x] = find(f[x]);
	return x;
}
int main()
{int n,m,a,b;
	while (cin >> n >> m) 
		{for (int i = 1;i <= n; i++) f[i] = i;
		for (int i = 1;i <= m; i++) 
			{cin >> a >> b;
			if (find(a) != find(b)) f[f[a]] = f[b];
			}
		int ans = 0;
		for (int i = 1;i <= n; i++) 
			if (f[i] == i) ans++;
		cout << ans-1 << endl; 
		}
	return 0;
}
