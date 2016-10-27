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
struct node{
    int s[2];
};
int a[100100],d[100100],cou;
node tree[100100];
int newnode() {
    cou++;
    tree[cou].s[0] = tree[cou].s[1] = 0;
    return cou;
}
void ins(int k) {
    int now = 1;
    for (int i = 15;i >= 0; i--) {
        int t = (k&(1<<i))?1:0;
        if (tree[now].s[t] == 0) {
            int sav = newnode();
            tree[now].s[t] = sav;
        }
        now = tree[now].s[t];
    }
}
int query(int k) {
    int ans = 0,now = 1;
    for (int i = 15;i >= 0; i--) {
        int t = (k&(1<<i))?0:1;
        if (tree[now].s[t]) {
            now = tree[now].s[t];
            if (t) ans += (1<<i);
        } else {
            now = tree[now].s[1-t];
            if (!t) ans += (1<<i);
        }
    }
    return ans;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(d,0,sizeof(d));
        int n,m;
        scanf("%d%d",&n,&m);
        cou = 0;newnode();
        for (int i = 1;i <= n; i++) {
            scanf("%d",&a[i]);
            ins(a[i]);
        }
        int u,v;
        for (int i = 1;i <= m; i++) {
            scanf("%d%d",&u,&v);
            d[u]++;d[v]++;
        }
        int ans = 0,cou = 0;
        for (int i = 1;i <= n; i++) {
            //Acout << d[i] << " ";
            if (d[i]%2 == 1) cou++;
            if ((d[i]+1)/2%2 == 1) ans ^= a[i];
        }
        if (cou == 1 || cou >= 3) puts("Impossible");
        else {
            if (cou == 0) ans ^= query(ans);
            printf("%d\n",ans);
        }
    }
	return 0;
}
