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
int rho[8] = {89,91,97,101,113,119,129,131};
int main()
{
	for (int i = 1;i <= 10; i++) {
		int t = -rand();
		cout << (-t + (t & 0x7fffffff)) << endl;
	}
	return 0;
}
