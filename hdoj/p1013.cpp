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
int sum(int k)
{
	int f = 0;
	while (k)
	{
		f += k%10;
		k/= 10;
	}
	return f;
}
int main()
{
	string st;
	while (cin >> st)
	{
		if (st == "0") break;
		int n = 0;
		for (int i = 0;i < st.size(); i++)
			n += st[i] - '0';
		while (n >= 10) n = sum(n);
		printf("%d\n",n);
	}
	return 0;
}
