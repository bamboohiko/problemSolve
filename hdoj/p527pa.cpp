#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	long long a,b,ans = 0;
	cin >> a >> b;
	while (b)
	{
		ans += a/b;
		long long t = a;
		a = b;
		b = t%b;
	}
	cout << ans << endl;
	return 0;
}
