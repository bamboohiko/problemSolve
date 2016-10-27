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
string st;
set<char> S;
int main() {
    int n;
    scanf("%d",&n);
    for (int ca = 1;ca <= n; ca++) {
        cin >> st;
        int ans = 0;
        S.clear();
        for (int i = 0;i < st.size(); i++) {
            if (!S.count(st[i])) {
                S.insert(st[i]);
                ans++;
            }
        }
        printf("Case #%d: %d\n",ca,ans);
    }
	return 0;
}
