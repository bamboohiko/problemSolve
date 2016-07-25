#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 1 << 30;
int a[100],fin,n,rec,len,use[100],ans[100];
void dfs(int k)
{
	cout << k << endl;
	if (fin) return;
	if (k == rec+1) 
		{fin = len;
		return;
		}
	int l = upper_bound(a,a+n,len-ans[k]) - a-1;
	for (int i = l;i >= 0; i--)
		if (!use[i])
			{use[i] = 1;
			ans[k] += a[i];
			if (ans[k] < len) dfs(k);
			else 
				{dfs(k+1);
				return;
				}
			ans[k] -= a[i];
			use[i] = 0;
			}
}
int main()
{
	while (cin >> n && n)
		{int sum = 0;
		for (int i = 0;i < n; i++)
			{cin >> a[i];
			sum += a[i];
			}
		sort(a,a+n);
		fin = 0;
		for (int i = sum/a[0];i > 1; i--)
			if (!(sum%i) && !fin) 
				{cout << " " << i << endl;
				rec = i;len = sum/i;
				dfs(1);
				}
		cout << fin << endl;
		}
	return 0;
}
