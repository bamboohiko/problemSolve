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
string s1,s2;
int len[100];
int main() {
    int t,n,m = 60;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        cin >> s1;
        for (int i = 0;i < m; i++) len[i] = m-i;
        for (int k = 2;k <= n; k++) {
            cin >> s2;
            for (int i = 0;i < m; i++) {
                int ml = 0;
                for (int j = 0;j < m; j++) {
                    int x = i,y = j;
                    while (s1[x] == s2[y]) x++,y++;
                    ml = max(ml,x-i);
                }
                len[i] = min(len[i],ml);
            }
        }
        int ans = 0;
        for (int i = 1;i < m; i++) {
            if (len[i] > len[ans]) ans = i;
            if (len[i] == len[ans])
                for (int x = ans,y = i;y < m;x++,y++)
                    if (s1[x] != s1[y]) {
                        if (s1[y] < s1[x]) ans = i;
                        break;
                    }
        }
        if (len[ans] < 3) puts("no significant commonalities");
        else {
            //cout << ans << " " << len[ans] << endl;
            for (int i = ans;i < ans+len[ans]; i++) putchar(s1[i]);
            puts("");
        }
    }
	return 0;
}

