#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<cmath>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
typedef long long LL;
const string st[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int main() {
    string a,b;
    cin >> a >> b;
    int x,y;
    for (int i = 0;i < 7; i++) if (a == st[i]) {x = i;break;}
    for (int i = 0;i < 7; i++) if (b == st[i]) {y = i;break;}
    x = (y+7-x)%7;
    if (x == 0 || x == 2 || x == 3) puts("YES");
    else puts("NO");
	return 0;
}
