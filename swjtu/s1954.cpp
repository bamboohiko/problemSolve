#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{int n = 3,k,s1 = 0,s2 = 0;
	for (int i = 1;i <= n; i++)
		for (int j = 1;j <= n; j++)
			{cin >> k;
			if (i == j) s1 += k;
			if (i+j == n+1) s2 += k;
			}
	cout << s1 << " " << s2 << endl;
	return 0;
}
