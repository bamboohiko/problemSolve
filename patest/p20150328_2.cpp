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
struct point{
	string st;
	int x,next;
};
point sav[100100];
vector<point> a;
string st;
int fig(string& st)
{
	int ans = 0;
	for (int i = 0;i <st.size(); i++)
		ans = ans*10 + st[i] - '0';
	return ans;
}
int main()
{
	int head,n,k;
	cin >> head >> n >> k;
	for (int i = 1;i <= n; i++)
	{
		cin >> st;
		int loc = fig(st);
		sav[loc].st = st;
		cin >> sav[loc].x >> sav[loc].next;
	}
	a.push_back((point){"",0,0});
	while (head != -1)
	{
		a.push_back(sav[head]);
		head = sav[head].next;
	}
	int turn = 1;
	while (turn*k <= n)
	{
		for (int i = 1;i <= k >> 1; i++)	
		{
			swap(a[turn*k-i+1],a[turn*k-k+i]);
		//cout << turn*k-i+1 << " " << turn*k-k+i << endl;
	}
		turn++;
	}
	a.push_back((point){"-1",0,0});
	for (int i = 1;i <= n; i++)
		cout << a[i].st << " " << a[i].x << " " << a[i+1].st << endl; 
	return 0;
}
