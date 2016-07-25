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
int cnt[110];
int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        memset(cnt,0,sizeof(cnt));
        scanf("%d%d%d",&n,&m,&l);
        for (int i = 1;i <= n; i++) {
            cin >> st;
            int len = st.size();cnt[1]++;
            for (int j = 0;j < len; j++) {
                for (int k = 1; ; k++)
                    if (j-k >= 0 && j+k < len && st[j-k] == st[j+k]) cnt[2*k+1]++;
                if (j > 0 && st[j] == st[j-1])
                    for (int k = 1; ; k++)
            }
        }
    }
	return 0;
}

