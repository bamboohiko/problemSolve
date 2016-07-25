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
long long f[50];
int main()
{
	f[1] = 1;
	for (int i = 2;i < 30; i++) f[i] = (f[i-1]+1)*2;
	int n;
	while (cin >> n) 
		cout << f[n] << endl;
	return 0;
}
