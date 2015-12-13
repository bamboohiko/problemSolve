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
string st;
int f[20][30];
void init() {
    for (int i = 0;i < 26; i++) f[1][i] = 1;
    for (int i = 2;i <= 10; i++) {
        for (int j = 1;j < 26; j++) f[i][0] += f[i-1][j];
        for (int j = 1;j <= 26-i; j++) f[i][j] = f[i][j-1] - f[i-1][j];
    }
}
int main() {
    init();
    while (cin >> st) {
        int ans = 0,n = st.length();
        for (int i = 1;i < n; i++) {
            if (st[i] < st[i-1]) {
                ans = -1;
                break;
            }
        }
        if (ans == -1) {
            printf("%d\n",0);
            break;
        }
        for (int i = n;i > 0; i--) {
            for (int j = 0;j <= st[n-i]-'a'; j++) ans += f[i][j];
        }
        printf("%d\n",ans);
    }
	return 0;
}
