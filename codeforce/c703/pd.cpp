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
int a[1000100],loc[1000100],rec[1000100],siz;
map<int,int> cnt;
struct point{
    int x,y;
};
point p[1000100];
int form(int x) {
    return (x-1)/siz + 1;
}
bool cmp(int a,int b) {
    if (form(p[a].x) == form(p[b].x)) return p[a].y < p[b].y;
    else return form(p[a].x) < form(p[b].x);
}
int main() {
    int n,q;
    scanf("%d",&n);
    siz = sqrt(n);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&a[i]);
        cnt[a[i]] = 0;
    }
    scanf("%d",&q);
    for (int i = 1;i <= q; i++) {
        scanf("%d%d",&p[i].x,&p[i].y);
        loc[i] = i;
    }
    sort(loc+1,loc+q+1,cmp);
    int l = 0,r = 0,ans = 0;
    for (int i = 1;i <= q; i++) {
        int k = loc[i];
        while (r < p[k].y) {
            if (cnt[a[++r]] == 0) ans ^= a[r];ans ^= a[r];
            cnt[a[r]]++;
        }
        while (r > p[k].y) {
            if (cnt[a[r]] == 1) ans ^= a[r];ans ^= a[r];
            cnt[a[r--]]--;
        }
        while (l < p[k].x) {
            if (cnt[a[l]] == 1) ans ^= a[l];ans ^= a[l];
            cnt[a[l++]]--;
        }
        while (l > p[k].x) {
            if (cnt[a[--l]] == 0) ans ^= a[l];ans ^= a[l];
            cnt[a[l]]++;
        }
        rec[k] = ans;
        //cout << p[k].x << " " << p[k].y << " " << ans << endl;
        //for (int i = 1;i <= n; i++) cout << cnt[i] << " ";cout << endl;
    }
    for (int i = 1;i <= q; i++) printf("%d\n",rec[i]);
	return 0;
}
