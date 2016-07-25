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
const int maxn = 1e5 + 100;
struct point{
    int t,v;
    bool operator <(const point &rhs) const {
        return t < rhs.t;
    }
};
priority_queue<int> Q;
point p[maxn];
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) scanf("%d",&p[i].t);
    for (int i = 1;i <= n; i++) scanf("%d",&p[i].v);
    sort(p+1,p+n+1);
    int j = n,ans = 0;
    for (int i = 5000;i >= 1; i--) {
        while (j >= 1 && p[j].t >= i) Q.push(p[j--].v);
        if (!Q.empty()) {
            int num = Q.top();Q.pop();ans += num;
        }
    }
    printf("%d\n",ans);
	return 0;
}

