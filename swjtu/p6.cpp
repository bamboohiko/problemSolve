#include<iostream>
using namespace std;
int main()
{int t;
	cin >> t;
	while (t--)
		{int n,k;
		cin >> n >> k;
		for (int i = 1;i <= n;i++)
			{k = n+i-2-k;
			if (k < i) break;
			}
		cout << k << endl;
		}
	return 0;
}
