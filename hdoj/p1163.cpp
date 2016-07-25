#include<iostream>
using namespace std;
int sum(int k)
{int t=0;
	while (k)
		{t=t+k%10;
		k/=10;
		}
	return (t > 9)?sum(t):t;
}
int main()
{int n,k,now;
	while (1)
		{cin >> n;
		if (!n) break;
		now = k = sum(n);
		for (int i = 1;i < n; i++) now = sum(now*k);
		cout << now << endl;
		}
	return 0;
}
