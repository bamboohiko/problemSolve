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
int main() {
    string st;
    cin >> st;
    char ch = 'a';
    int ans = 0;
    for (int i = 0;i < st.size(); i++) {
        int sav = abs(ch - st[i]);
        ans += min(sav,26-sav);
        ch = st[i];
    }
    printf("%d\n",ans);
	return 0;
}
