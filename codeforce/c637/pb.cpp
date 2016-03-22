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
set<string> S;
vector<string> V;
string st[200100];
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) cin >> st[i];
    for (int i = n;i >= 1; i--) {
        if (!S.count(st[i])) {
            S.insert(st[i]);
            cout << st[i] << endl;
        }
    }
	return 0;
}

