#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1010];
int main()
{int t;
	cin >> t;
	while (t--)
		{int n;
		cin >> n;
		for (int i = 0;i < n; i++) cin >> a[i];
		sort(a,a+n);
		for (int i = 0;i < n-1; i++) cout << a[i] << " ";
		cout << a[n-1] << endl;
		}
	
	return 0;
}

