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
struct point {
    int x,y;
};
point p[maxn];
int a[maxn],rec[maxn],loc[maxn],cnt[maxn],siz;
int form(int x) {
    return (x-1)/siz + 1;
}
bool cmp(int a,int b) {
    if (form(p[a].x) == form(p[b].x)) return p[a].y < p[b].y;
    else return form(p[a].x) < form(p[b].x);
}
int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    siz = sqrt(n);
    for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
    for (int i = 1;i <= q; i++) {scanf("%d%d",&p[i].x,&p[i].y);loc[i] = i;}
    sort(loc+1,loc+q+1,cmp);
    int l = 0,r = 0,ans = 0;
    for (int i = 1;i <= q; i++) {
        int k = loc[i];
        while (r < p[k].y) {
            if (cnt[a[++r]] == 0) ans++;
            cnt[a[r]]++;
        }
        while (r > p[k].y) {
            if (cnt[a[r]] == 1) ans--;
            cnt[a[r--]]--;
        }
        while (l < p[k].x) {
            if (cnt[a[l]] == 1) ans--;
            cnt[a[l++]]--;
        }
        while (l > p[k].x) {
            if (cnt[a[--l]] == 0) ans++;
            cnt[a[l]]++;
        }
        rec[k] = ans;
        //cout << p[k].x << " " << p[k].y << " " << ans << endl;
        //for (int i = 1;i <= n; i++) cout << cnt[i] << " ";cout << endl;
    }
    for (int i = 1;i <= q; i++) printf("%d\n",rec[i]);
    return 0;
}

