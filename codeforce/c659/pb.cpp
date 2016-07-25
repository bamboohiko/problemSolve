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
struct point{
    string st;
    int val;
    bool operator <(const point &rhs) const {
        return val > rhs.val;
    }
};
vector<point> a[10100];
int main() {
    int n,m,k;
    scanf("%d%d",&n,&m);
    point p;
    for (int i = 1;i <= n; i++) {
        cin >> p.st;scanf("%d%d",&k,&p.val);
        a[k].push_back(p);
    }
    for (int i = 1;i <= m; i++) {
        sort(a[i].begin(),a[i].end());
        if (a[i].size() > 2 && a[i][1].val == a[i][2].val) puts("?");
        else cout << a[i][0].st << " " << a[i][1].st << endl;
    }
	return 0;
}

