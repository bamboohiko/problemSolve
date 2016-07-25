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
struct date {
	int y,m,d;
	date(int y=0,int m=0,int d=0):y(y),m(m),d(d) {}
	bool operator <(const date& rhs) const {
		//cout << rhs.y << " " << rhs.m << " " << rhs.d << endl;
		if (m != rhs.m) return m < rhs.m;
		return d <= rhs.d;
	}
};
map<string,int> mouth;
void input(date& ans) {
	string st;
	cin >> st;
	ans.m = mouth[st];
	scanf("%d,%d",&ans.d,&ans.y);
}
bool spec(int y)
{
	if (y%4 || (!(y%100) && (y%400))) return false;
	return true;
}
int main()
{
	mouth["January"] = 1;
	mouth["February"] = 2;
	mouth["March"] = 3;
	mouth["April"] = 4;
	mouth["May"] = 5;
	mouth["June"] = 6;
	mouth["July"] = 7;
	mouth["August"] = 8;
	mouth["September"] = 9;
	mouth["October"] = 10;
	mouth["November"] = 11;
	mouth["December"] = 12;
	int t;
	date op,ed;
	scanf("%d",&t);
	for (int ca = 1;ca <= t; ca++) {
		input(op);
		input(ed);
		int ans = 0;
		date d(0,2,29); 
		if (op.y == ed.y) {
			if (spec(op.y) && op < d && d < ed) ans++;
		}
		else {
			if (spec(op.y) && op < d) ans++;
			if (spec(ed.y) && d < ed) ans++;
		}
		if (ed.y - op.y < 1e3) 
		{
			for (int i = op.y+1;i < ed.y; i++) 
				if (spec(i)) ans++;
		}
		else {
			int i,j;
			for (i = op.y+1;i%400; i++)
				if (spec(i)) ans++;
			for (j = ed.y-1;(j+1)%400; j--)
				if (spec(j)) ans++;
			cout << i << " " << j << endl;
			ans += (j-i+1)/400*97;
		}
		printf("Case #%d: %d\n",ca,ans);
	}
	return 0;
}
