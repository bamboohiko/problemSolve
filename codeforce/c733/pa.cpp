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
int v[6] = {'A','E','I','O','U','Y'};
int main() {
    string st;
    cin >> st;
    st = "A" + st + "A";
    int loc = 0,ans = 1,m = 6;
    for (int i = 0;i < st.size(); i++) {
        for (int j = 0;j < m; j++)
            if (st[i] == v[j]) {
                ans = max(ans,i-loc);
                loc = i;
                break;
            }
    }
    printf("%d\n",ans);
	return 0;
}
