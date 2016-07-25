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
int a[50010],p[50010];
int t[50010],n;
int lowbit(int k) {
    return k&(-k);
}
void add(int k,int x) {
    while (k <= n) {
        t[k] += x;
        k += lowbit(k);
    }
}
int query(int k) {
    int ans = 0;
    while (k >= 1) {
        ans += t[k];
        k -= lowbit(k);
    }
    return ans;
}
int find(int k) {
    int ans = 0;
    for (int i = 15;i >= 0;i--) {
        int ns = ans + (1 << i);
        if (ns > n) continue;
        if (query(ns) < k) ans = ns;
        if (query(ns) == k && query(ns-1) == k-1) {
            ans = ns;
            break;
        }
    }
    add(ans,-1);
    return n+1-ans;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) {
            scanf("%d",&a[i]);
            add(i,1);
        }
        for (int i = n;i >= 1; i--) {
            int loc = a[i] - a[i-1]+1;
            p[i] = find(loc);
        }
        for (int i = 1;i < n; i++) printf("%d ",p[i]);
        printf("%d\n",p[n]);
    }
	return 0;
}
