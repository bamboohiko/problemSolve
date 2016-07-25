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
const int maxn = 2e5 + 100;
LL l[maxn],r[maxn],nl[maxn],nr[maxn];
int loc[maxn],t[maxn];
bool lcmp(int x,int y) {
    if (l[x] == l[y]) return r[x] < r[y];
    return l[x] < l[y];
}
bool rcmp(int x,int y) {
    if (nr[x] == nr[y]) return x < y;
    return nr[x] < nr[y];
}
void add(int k,int n) {
    for (int i = k; i <= n; i += i&(-i))
        t[i] += 1;
}
int sum(int k) {
    int ans = 0;
    for (int i = k; i >= 1; i -= i&(-i))
        ans += t[i];
    return ans;
}
int main() {
    int T;
    int n,m,k;
    scanf("%d",&T);
    for (int ca = 1; ca <= T; ca++) {
        memset(t,0,sizeof(t));
        scanf("%d%d%d",&n,&m,&k);
        for (int i = 1; i <= k; i++) {
            scanf("%d%d",&l[i],&r[i]);
            loc[i] = i;
        }
        //for (int i = 1;i <= n; i++) cout << l[i] << " ";cout << endl;
        //for (int i = 1;i <= n; i++) cout << r[i] << " ";cout << endl;
        sort(loc+1,loc+k+1,lcmp);
        int rec = 0,hit = 0;
        LL ans = 0;
        for (int i = 1; i <= k; i++) {
            nl[i] = l[loc[i]];
            nr[i] = r[loc[i]];
            loc[i] = i;
        }
        sort(loc+1,loc+k+1,rcmp);
        //for (int i = 1;i <= k; i++) cout << loc[i] << " ";cout << endl;
        for (int i = 1; i <= k; i++) {
            add(loc[i],k);
            ans += sum(k) - sum(loc[i]);
        }
        printf("Test case %d: %lld\n",ca,ans);
    }
    return 0;
}

