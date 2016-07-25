#include<iostream>
#include<cstdio>
using namespace std;
int a[1010];
int main()
{int t;
	cin >> t;
	while (t--)
		{int n,odd = 0,even = 0,c1 = 1,c2 = 0;
		cin >> n;
		for (int i = 1;i <= n; i++)
			{cin >> a[i];
			if (i%2) odd += a[i];
			else even += a[i];
			}
		if (odd != even) c1 = 0;
		for (int i = 1;i < n; i++,n--)
			if (a[i] != a[n]) 
				{c2 = 1;
				break;
				}
		if (c1 && c2) printf("Yes\n");
		else printf("No\n");
		}
	return 0;
}

