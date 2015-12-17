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
struct Act{
    int k,l,r;
    LL v;
};
map<int,int> dir;
vector<int> sav;
Act a[100100];
LL t[300100];
int n,m,cnt;
int lowbit(int k) {
    return k&(-k);
}
void add(int k,LL x) {
    while (k <= cnt) {
        t[k] += x;
        k += lowbit(k);
    }
}
LL query(int k) {
    LL ans = 0;
    while (k > 0) {
        ans += t[k];
        k -= lowbit(k);
    }
    return ans;
}
int main() {
    while (scanf("%d%d",&n,&m) != EOF) {
        dir.clear();
        memset(t,0,sizeof(t));
        sav.clear();sav.push_back(-1);
        for (int i = 1;i <= m; i++) {
            scanf("%d",&a[i].k);
            if (!a[i].k) {
                scanf("%d%d%lld",&a[i].l,&a[i].r,&a[i].v);
                sav.push_back(a[i].l);sav.push_back(a[i].r);
            } else {
                scanf("%d",&a[i].l);
                sav.push_back(a[i].l);
            }
        }
        sort(sav.begin(),sav.end());cnt = 0;
        for (int i = 1;i < sav.size();i++)
            if (sav[i] != sav[i-1]) dir[sav[i]] = ++cnt;
        for (int i = 1;i <= m; i++) {
            if (!a[i].k) {
                //cout << dir[a[i].l] << ":" << dir[a[i].r] << endl;
                add(dir[a[i].l],a[i].v);
                add(dir[a[i].r]+1,-a[i].v);
            } else {
                //cout << dir[a[i].v] << endl;
                printf("%lld\n",query(dir[a[i].l]));
            }
        }
    }
	return 0;
}
