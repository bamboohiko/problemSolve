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
map<LL,LL> val;
set<LL> S;
LL fa(LL u,LL v) {
    S.clear();
    while (u) {
        S.insert(u);
        u >>= 1;
    }
    while (v) {
        if (S.count(v)) return v;
        v >>= 1;
    }
    return 1;
}
void add(LL u,LL s,LL w) {
    while (u > s) {
        if (!val.count(u)) val[u] = w;
        else val[u] += w;
        //cout << u << " " << w <<endl;
        u >>= 1;
    }
}
LL query(LL u,LL s) {
    LL ans = 0;
    while (u > s) {
        if (val.count(u)) ans += val[u];
        //cout << u << " " << val[u] << endl;
        u >>= 1;
    }
    return ans;
}
int main() {
    int q;
    scanf("%d",&q);
    int op;LL u,v,w;
    while (q--) {
        scanf("%d%I64d%I64d",&op,&u,&v);
        if (op == 1) {
            scanf("%I64d",&w);
            LL s = fa(u,v);
            add(u,s,w);
            add(v,s,w);
        } else {
            LL s = fa(u,v);
            printf("%I64d\n",query(u,s)+query(v,s));
        }
    }
	return 0;
}
