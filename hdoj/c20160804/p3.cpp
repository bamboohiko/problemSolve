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
int g[32];
set<int> S;
void grundy(int k) {
    S.clear();
    for (int i = 2;i <= 4; i++) {
        if (k < i) break;
        S.insert(g[k-i]);
    }
    for (int i = 1;i <= 32; i++)
        if (!S.count(i)) {
            g[k] = i;
            break;
        }
}
int main() {
    memset(g,-1,sizeof(g));g[0] = g[1] = g[2] = 0;
    for (int i = 3;i <= 32; i++) {
        grundy(i);
        cout << g[i] << " ";
    }
    cout << endl;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        int sum = 0,gsum = 0,k;
        for (int i = 1;i <= n; i++) {
            scanf("%d",&k);
            sum ^= k;
            int one = 0;
            for (int j = k;j > 0;j -= j&(-j)) one++;
            if (one > 2) gsum ^= g[one];
        }
        //cout << sum << gsum << endl;
        int ok = 0;
        if (sum > 0 && gsum == 0) ok = 1;
        if (sum == 0 && gsum > 0) ok = 1;
        if (n == 1) ok = 1;
        if (ok) puts("First player wins.");
        else puts("Second player wins.");
    }
	return 0;
}
