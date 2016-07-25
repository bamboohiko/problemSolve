#include<iostream>
#include<set>
using namespace std;
set<int> s;
int main()
{int n,x;
	while (cin >> n)
		{s.clear();
		int ans = 0;
		for (int i = 1;i <= n; i++)
			{cin >> x;
			if	(!s.count(x)) 
				{ans++;
				s.insert(x);
				}
			}
		cout << ans << endl;
		}
	return 0;
}
