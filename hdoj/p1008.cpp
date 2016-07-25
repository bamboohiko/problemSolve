#include<iostream>
using namespace std;
int main()
{int n;
	while (cin >> n && n != 0)
		{int x = 0,x0 = 0,sum = 0;
		for (int i = 1;i <= n;i++)
			{cin >> x;
			sum+=5;
			if (x > x0) sum+=(x-x0)*6;
			else sum+=(x0-x)*4;
			x0 = x;
			}
		cout << sum << endl;
		}
	return 0;
}
