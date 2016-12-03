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
int a[20],b[20],sava[10010],savb[10010];
bool f[10010];
void dp(int n,int a[],int b[],int &m) {
    memset(f,0,sizeof(f));
    f[0] = true;
    for (int i = 10; i >= 1; i--) {
        for (int k = 1; k <= a[i]; k <<= 1) {
            for (int j = n; j >= k*i; j--)
                f[j] = f[j] || f[j-k*i];
            a[i] -= k;
        }
        for (int j = n; j >= a[i]*i; j--)
            f[j] = f[j] || f[j-a[i]*i];
    }
    for (int i = 1;i <= n; i++)
        if (f[i]) {
            b[m++] = i;
            //cout << i << " ";
        }
    //cout << endl;
}
int main() {
    int t,n,ma,mb;
    scanf("%d",&t);
    while (t--) {
        memset(a,0,sizeof(a));memset(sava,0,sizeof(sava));ma = 0;
        memset(b,0,sizeof(b));memset(savb,0,sizeof(savb));mb = 0;
        scanf("%d",&n);
        int uct = 0,ct = 0;
        int cost,fi;
        for (int i = 1;i <= n; i++) {
            scanf("%d%d",&cost,&fi);
            if (fi) {a[cost]++;ct += cost;}
            else  {b[cost]++;uct += cost;}
        }
        if (uct >= ct) printf("%d\n",uct);
        else {
            dp(ct,a,sava,ma);
            dp(uct,b,savb,mb);
            int loc = lower_bound(sava,sava+ma,(ct-uct)/2) - sava;
            //cout << sava[loc] << endl;
            int ans = max(uct + sava[loc],ct - sava[loc]);
            if (loc) ans = min(ans ,max(uct + sava[loc],ct - sava[loc]));
            for (int i = 0;i < mb; i++) {
                loc = lower_bound(sava,sava+ma,savb[i] + (ct-uct)/2) - sava;
                ans = min(ans,max(sava[loc] - savb[i],(ct-sava[loc])-(uct-savb[i])) + uct);
                if (loc) ans = min(ans, max(sava[loc-1] - savb[i],(ct-sava[loc-1])-(uct-savb[i])) + uct);
            }
            printf("%d\n",ans);
        }
    }
	return 0;
}
