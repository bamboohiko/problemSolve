#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{string a,b;
	while (cin >> a >> b)
		{int len,sum=0;
		len = min(a.length(),b.length());
		for (int i = 0;i < len; i++)
			if (a[i] == b[i]) sum++;
		cout << sum << endl;
		}
	return 0;
}
