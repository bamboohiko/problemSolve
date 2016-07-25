#include<iostream>
using namespace std;
int a[20];
int main()
{int n=9,ans=0;
	for (int i = 1;i <= 9;i++ ) cin >> a[i];
	for (int i = 1;i < n;i++ )
		for (int j = (i+1);j <= n; j++)
			if (a[i]>a[j]) ans++;
	cout << ans << endl;
	return 0;
}
