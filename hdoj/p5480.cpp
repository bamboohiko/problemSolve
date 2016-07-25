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
const int maxn = 1e5 + 10;
int visx[maxn],visy[maxn],tx[maxn],ty[maxn];
int n,m,k,q;
int lowbit(int k) {
    return k&(-k);
}
void updatax(int k,int d) {
    while (k <= n) {
        tx[k] += d;
        k += lowbit(k);
    }
}
int sumx(int k) {
    int ans = 0;
    while (k > 0) {
        ans += tx[k];
        k -= lowbit(k);
    }
    return ans;
}
void updatay(int k,int d) {
    while (k <= m) {
        ty[k] += d;
        k += lowbit(k);
    }
}
int sumy(int k) {
    int ans = 0;
    while (k > 0) {
        ans += ty[k];
        k -= lowbit(k);
    }
    return ans;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(visx,0,sizeof(visx));
        memset(visy,0,sizeof(visy));
        memset(tx,0,sizeof(tx));
        memset(ty,0,sizeof(ty));
        scanf("%d%d%d%d",&n,&m,&k,&q);
        int x,y;
        for (int i = 1;i <= k; i++) {
            scanf("%d%d",&x,&y);
            if (!visx[x]) {
                visx[x] = 1;
                updatax(x,1);
            }
            if (!visy[y]) {
                visy[y] = 1;
                updatay(y,1);
            }
        }
        int x1,y1,x2,y2;
        for (int i = 1;i <= q; i++) {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            //cout << (sumy(y2) - sumy(y1-1)) << " " << (sumy(x2) - sumy(x1-1)) << endl;
            if ((sumy(y2) - sumy(y1-1) == y2-y1+1) || (sumx(x2) - sumx(x1-1) == x2-x1+1)) printf("Yes\n");
            else printf("No\n");
        }
    }
	return 0;
}

