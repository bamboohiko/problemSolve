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
const int mod = 772002;
const int siz = 33555000;
int mov[8][2] = {0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};
int dp[siz],pre[30];
int main() {
    int n,m,ca = 0;
    char ch;
    while (scanf("%d%d%*c",&n,&m) != EOF) {
        memset(pre,0,sizeof(pre));
        for (int i = 0;i < n; i++) {
            for (int j = 0;j < m; j++) {
                ch = getchar();
                if (ch == 'X') {
                    //cout << i << " " << j << endl;
                    for (int k = 0;k < 8; k++) {
                        int x = i+mov[k][0],y = j+mov[k][1];
                        if (x < 0 || x >= n || y < 0 || y >= m) continue;
                        pre[x*m+y] |= (1 << (i*m+j));
                    }
                }
            }
            getchar();
        }
        int sum = n*m;
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for (int S = 0; S < (1<<sum); S++)
            if (dp[S]!=0) {
                for (int i = 0; i < sum; i++)
                    if (((S&pre[i])==pre[i]) && !(S&(1<<i))) {
                        dp[S|(1<<i)] = (dp[S|(1<<i)] + dp[S])%mod;
                    }
            }
        printf("Case #%d: %d\n",++ca,dp[(1 << sum)-1]);
    }
	return 0;
}
