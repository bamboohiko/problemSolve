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
priority_queue<int,vector<int>,greater<int> > Q;
const int maxn = 1e5 + 10;
int vis[maxn],loc[maxn];
int a[maxn],d[maxn],n,m;
bool pass(int k) {
    memset(vis,0,sizeof(vis));
    for (int i = k;i >= 1; i--)
        if (d[i] && !vis[d[i]]) vis[d[i]] = i;
    int use = 0,cnt = m;
    for (int i = 1;i <= k; i++) {
        if (d[i] && vis[d[i]] == i) {
            if (i - use >= a[d[i]]+1) {
                use += a[d[i]] + 1;
                cnt--;
            } else return false;
        }
    }
    if (cnt == 0) return true;
    else return false;
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; i++) scanf("%d",&d[i]);
    for (int j = 1;j <= m; j++) scanf("%d",&a[j]);
    int l = 0,r = n;
    while (l+1 < r) {
        int mid = (l + r) >> 1;
        if (pass(mid)) r = mid;
        else l = mid;
        //cout << l << " " << r << endl;
    }
    if (pass(r)) printf("%d\n",r);
    else puts("-1");
	return 0;
}

