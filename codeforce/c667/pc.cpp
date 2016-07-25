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
bool vis[300100][2];
set<string> S;
string st,ss;
int main() {
    cin >> st;
    int n = st.size();
    vis[n][0] = vis[n][1] = true;
    if (n >= 7) {
        vis[n-2][0] = true;
        ss = "";ss += st[n-2];ss += st[n-1];S.insert(ss);
    }
    if (n >= 8) {
        vis[n-3][1] = true;
        ss = "";ss += st[n-3];ss += st[n-2];ss += st[n-1];S.insert(ss);
    }
    for (int i = n-4;i >= 5; i--) {
        if (vis[i+2][1] || (vis[i+2][0] && (st[i] != st[i+2] || st[i+1] != st[i+3]))) {
            vis[i][0] = true;
            ss = "";ss += st[i];ss += st[i+1];S.insert(ss);
        }
        if (i+5 > n) continue;
        if (vis[i+3][0] || (vis[i+3][1] && (st[i] != st[i+3] || st[i+1] != st[i+4] || st[i+2] != st[i+5]))) {
            vis[i][1] = true;
            ss = "";ss += st[i];ss += st[i+1];ss += st[i+2];S.insert(ss);
        }
    }
    //for (int i = n-1;i >= 0; i--)
    //    cout << vis[i][0] << " " << vis[i][1] << endl;
    printf("%d\n",S.size());
    for (set<string>::iterator i = S.begin();i != S.end(); i++)
        cout << *i << endl;
	return 0;
}

