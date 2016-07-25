#include<iostream>
using namespace std;
long long f[100];
int main()
{int n;
	f[1] = 1;f[2] = 2;
	for (int i = 3;i <= 50; i++) f[i] = f[i-1]+f[i-2];
	while (cin >> n) cout << f[n] << endl;
	return 0;
}
