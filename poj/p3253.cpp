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
priority_queue<LL,vector<LL>,greater<LL> > Q;
int main() {
    int n;LL k;
    while (scanf("%d",&n) != EOF) {
        for (int i = 1;i <= n; i++) {
            scanf("%I64d",&k);
            Q.push(k);
        }
        LL ans = 0;
        for (int i = 2;i <= n; i++) {
            LL k1 = Q.top();Q.pop();
            LL k2 = Q.top();Q.pop();
            k1 += k2;
            ans += k1;
            Q.push(k1);
        }
        printf("%I64d\n",ans);
    }
	return 0;
}

