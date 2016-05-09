#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 91000;
ll arr[maxn], T[maxn << 2];
struct Node{
    ll  d, v, lw, rw, k;
}node[maxn];
int n;
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 |1

void pushUP(int rt){
    T[rt] = max(T[rt<<1], T[rt<<1|1]);
}

void update(int p, ll v, int l, int r, int rt){
    if(p == l && l == r){
        T[rt] = v;
        return ;
    }
    int m = (l + r) >> 1;
    if(p <= m) update(p, v, lson);
    else update(p, v, rson);
    pushUP(rt);
}

ll query(int L, int R, int l, int r, int rt){
    if(L <= l && r <= R){
        return T[rt];
    }
    int m = (l + r) >> 1;
    ll ret = 0;
    if(L <= m) ret = max(ret, query(L, R, lson));
    if(R > m) ret = max(ret, query(L, R, rson));
    return ret;
}

int main(){
    //freopen("data.out", "w", stdout);
    //freopen("data4.in", "r", stdin);
    ll tmp;
    while(scanf("%d", &n) != EOF){
        memset(T, 0, sizeof(T));
        int ind = 1;
        for(int i = 1; i <= n; ++i){
            scanf("%lld%lld%lld", &node[i].d, &node[i].v, &node[i].k);
            arr[ind++] = node[i].d;
            arr[ind++] = max(node[i].d - node[i].k, (ll)0);
            arr[ind++] = node[i].d + node[i].k;
            node[i].lw = max(node[i].d - node[i].k, (ll)0);
            node[i].rw = node[i].d + node[i].k;
        }
        sort(arr + 1, arr + ind + 1);
        int len = unique(arr + 1, arr + ind + 1 ) - arr;
        ll mx = 0;
        for(int i = 1; i <= n; ++i){
            node[i].d = lower_bound(arr + 1, arr + len, node[i].d) - arr;
            node[i].lw = lower_bound(arr + 1, arr + len, node[i].lw) - arr;
            node[i].rw = lower_bound(arr + 1, arr + len, node[i].rw) - arr;
            //cout << node[i].d << " " << node[i].t << endl;
            tmp = query(node[i].lw, node[i].rw, 1, 3*n, 1);
            update(node[i].d, tmp + node[i].v, 1, 3*n, 1);
            mx = max(tmp+node[i].v, mx );
         //   cout << tmp << " "  << tmp + node[i].v<< endl;
        }
        cout << mx << endl;
    }
}
