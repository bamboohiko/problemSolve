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
const int INF = 1e6;
string s;
int main()
{
	int a
	while (cin >> a >> s)
	{
		int ans = INF,loc;
		for (int q = 0;q <= 4; i++)
		{
			if (a < pow(q-1)) break;
			int x = 0;
			if (s[0] == '0') x = 1;
			for ( ;x <= a; x++)
				if (figure(x,a) < pow2(q)) 
				{
					if (x < ans)
					{
						ans = x;
						loc = q;
					}
					break;
				} 
		}
		
	}
	return 0;
}
