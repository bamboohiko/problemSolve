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
{int n,m;
	while (cin >> n >> m)
	{
		if (n == 1) cout << 0 << endl;
		else cout << (m-1)%n << endl;
	}
	return 0;
}
