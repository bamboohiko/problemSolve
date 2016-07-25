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
using namespace std;
const int maxn = 5e3 + 10;
int a[maxn],t[maxn],n;
int lowbit(int k) {
    return k&(-k);
}
int query(int k) {
    int ans = 0;
    while (k > 0) {
        ans += t[k];
        k -= lowbit(k);
    }
    return ans;
}
void updata(int k,int d) {
     while (k <= n) {
        t[k] += d;
        k += lowbit(k);
     }
}
int main() {
    while (scanf("%d",&n) != EOF) {
        memset(t,0,sizeof(t));
        int rec = 0;
        for (int i = 1;i <= n; i++) {
            scanf("%d",&a[i]);
            rec += query(n) - query(a[i]);
            updata(a[i]+1,1);
        }
        int ans = rec;
        for (int i = 1;i < n; i++) {
            rec = rec - a[i] + (n-1-a[i]);
            ans = min(ans,rec);
        }
        printf("%d\n",ans);
    }
	return 0;
}

