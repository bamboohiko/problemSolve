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
struct point {
	int x,y;
};
vector<point> sav;
int main()
{
	int n,m;
	while (cin >> n >> m)
	{
		if (!m) 
			if (sav.size()) continue;
			else n = 0,m = 1;
		sav.push_back((point){n*m,m-1});
	}
	cout << sav[0].x << " " << sav[0].y;
	for (int i = 1;i < sav.size(); i++)
		cout << " " << sav[i].x << " " << sav[i].y;
	cout << endl;
	return 0;
}
