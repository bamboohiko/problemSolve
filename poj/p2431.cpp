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
const int maxn = 1e6 + 100;
priority_queue<int> Q;
struct point {
    int dis,p;
    bool operator <(const point &rhs) const {
        if (dis < rhs.dis) return true;
        else return false;
    }
};
point a[maxn];
int main() {
    int n,l,p;
    while (scanf("%d",&n) != EOF) {
        while (!Q.empty()) Q.pop();
        for (int i = 1;i <= n; i++)
            scanf("%d%d",&a[i].dis,&a[i].p);
        scanf("%d%d",&a[n+1].dis,&p);
        sort(a+1,a+n+1);
        Q.push(p);
        int ans = -1;
        int s = a[n+1].dis;
        for (int i = n;i >= 0; i--) {
            while (!Q.empty() && s > a[i].dis) {
                ans++;
                int t = Q.top();s -= t;
                Q.pop();
            }
            //cout << i << " " << ans << endl;
            if (s > a[i].dis) {
                ans = -1;
                break;
            } else {
                Q.push(a[i].p);
            }

        }
        printf("%d\n",ans);
    }
	return 0;
}

