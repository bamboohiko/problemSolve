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
int main()
{
	int n,k,cou[8];
	memset(cou,0,sizeof(cou));
	cin >> n;
	for (int i = 0;i < n; i++) {
		cin >> k;
		cou[i%7] += k;
	}
	for (int i = 0;i < 7; i++)
		cout << cou[i] << endl;
	return 0;
}
