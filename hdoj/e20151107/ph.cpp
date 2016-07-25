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
struct point {
    int v;
    int s[2];
};
vector<point> t;
int root,m;
LL pow2[30];
void init() {
    pow2[0] = 1;
    for (int i = 1;i <= 20; i++)
        pow2[i] = pow2[i-1] << 1;
}
int newnode() {
    point p;
    p.v = 0;
    p.s[0] = p.s[1] = -1;
    t.push_back(p);
    return t.size()-1;
}
void build(int k) {
    int now = root;
    t[now].v++;
    for (int i = 20;i >= 0;i--) {
        cout << now << " ";
        int son = ((1 << i)&k)?1:0;
        if (t[now].s[son] == -1) {
            int sav = newnode();
            t[now].s[son] = sav;
        }
        now = t[now].s[son];
        t[now].v++;
    }
    cout << now << endl;
}
LL query(int now,int i,int sum) {
    printf("%d %d %d\n",now,i,sum);
    if (sum >= m) return pow2[t[now].v];
    if (i < 0) return 0;
    int ans = 0,v1 = t[t[now].s[0]].v,v2 = t[t[now].s[1]].v;
    if (t[now].s[0] != -1) ans += query(t[now].s[0],i-1,sum)*((v2 << 1)+1);
    if (t[now].s[1] != -1) ans += query(t[now].s[1],i-1,sum+(1 << i))*(v1 + 1);
    return ans;
}
int main() {
    init();
    int T,n;
    scanf("%d",&T);
    for (int ca = 1;ca <= T; ca++) {
        t.clear();
        root = newnode();
        scanf("%d%d",&n,&m);
        int k;
        for (int i = 1;i <= n; i++) {
            scanf("%d",&k);
            build(k);
        }
        printf("Case #%d: %lld\n",ca, query(root,20,0));
    }
	return 0;
}
