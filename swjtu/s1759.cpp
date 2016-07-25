#include<iostream>
#include<cstdio>
using namespace std;
int main()
{int t;
long long x,y,z;
	cin >> t;
	for (int i = 1;i <= t; i++)
		{cin >> x >> y >> z;
		printf("Case #%d: ",i);
		int ans = (x+y)%z;
		if (ans < 0) ans += z;
		cout << ans << endl;
		}
	return 0;
}

