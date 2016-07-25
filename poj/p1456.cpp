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
const int maxn = 1e4;
vector<int> a[maxn + 10];
priority_queue<int> Q;
int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        for (int i = 1;i <= maxn; i++) a[i].clear();
        while (!Q.empty()) Q.pop();
        int k,d,maxt = 0;
        for (int i = 1;i <= n; i++) {
            scanf("%d%d",&k,&d);
            a[d].push_back(k);
            maxt = max(maxt,d);
        }
        int ans = 0;
        for (int i = maxt;i > 0; i--) {
            for (int j = 0;j < a[i].size(); j++) Q.push(a[i][j]);
            if (!Q.empty()) {ans += Q.top();Q.pop();}
        }
        printf("%d\n",ans);
    }
	return 0;
}

